/*
 * CloseObjectsVector.h
 *
 *  Created on: 11/06/2012
 *      Author: victor
 */

#ifndef CLOSEOBJECTSVECTOR_H_
#define CLOSEOBJECTSVECTOR_H_

#include "system/util/SortedVector.h"

namespace engine {
 namespace util {
  namespace u3d {
   class QuadTreeEntry;
  }
 }
}

using namespace engine::util::u3d;

class CloseObjectsVector : public SortedVector<ManagedReference<QuadTreeEntry*> > {
public:
	int put(const ManagedReference<QuadTreeEntry*>& o) {
		int m = 0, l = 0;
		int r = Vector<ManagedReference<QuadTreeEntry*> >::elementCount - 1;

		while (l <= r) {
			m = (l + r) / 2;

			/*E& obj = Vector<E>::elementData[m];
			int cmp = compare(obj, o);*/

			int cmp = Vector<ManagedReference<QuadTreeEntry*> >::elementData[m].compareTo(o);

			if (cmp == 0) {
				switch (insertPlan) {
				case ALLOW_DUPLICATE:
					Vector<ManagedReference<QuadTreeEntry*> >::add(++m, o);
					break;
				case ALLOW_OVERWRITE:
					Vector<ManagedReference<QuadTreeEntry*> >::set(m, o);
					break;
				default:
					return -1;
				}

				return m;
			} else if (cmp > 0)
				l = m + 1;
			else
				r = m - 1;
		}

		if (r == m)
			m++;

		Vector<ManagedReference<QuadTreeEntry*> >::add(m, o);

		return m;
	}

	int find(const ManagedReference<QuadTreeEntry*>& o) const {
		if (ArrayList<ManagedReference<QuadTreeEntry*> >::size() == 0)
			return -1;

		int l = 0, r = Vector<ManagedReference<QuadTreeEntry*> >::elementCount - 1;
		int m = 0, cmp = 0;

		while (l <= r) {
			m = (l + r) / 2;

			cmp = Vector<ManagedReference<QuadTreeEntry*> >::elementData[m].compareTo(o);

			if (cmp == 0)
				return m;
			else if (cmp > 0)
				l = m + 1;
			else
				r = m - 1;
		}

		return -1;
	}
};

#endif /* CLOSEOBJECTSVECTOR_H_ */
