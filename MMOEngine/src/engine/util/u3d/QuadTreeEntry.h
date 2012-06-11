/*
 *	engine/util/u3d/QuadTreeEntry.h generated by engine3 IDL compiler 0.60
 */

#ifndef QUADTREEENTRY_H_
#define QUADTREEENTRY_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "system/lang/ref/Reference.h"

#include "system/lang/Math.h"

#include "system/util/SortedVector.h"

#include "engine/stm/TransactionalReference.h"

#include "engine/util/u3d/CloseObjectsVector.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observable.h"

#include "engine/util/u3d/Vector3.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/util/u3d/QuadTreeNode.h"

namespace engine {
namespace util {
namespace u3d {

class QuadTreeEntry : public Observable {
public:
	QuadTreeEntry(QuadTreeNode* n = NULL);

	void addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate = true);

	void removeInRangeObject(QuadTreeEntry* obj);

	void removeInRangeObject(int index);

	void removeInRangeObjects();

	bool isInRange(QuadTreeEntry* obj, float range);

	bool isInRange(float x, float y, float range);

	float getDistanceTo(QuadTreeEntry* obj);

	SortedVector<ManagedReference<QuadTreeEntry* > >* getCloseObjects();

	ManagedWeakReference<QuadTreeEntry* > getParent();

	QuadTreeEntry* getParentUnsafe();

	QuadTreeEntry* getRootParentUnsafe();

	bool containsPoint(float x, float y);

	ManagedWeakReference<QuadTreeEntry* > getRootParent();

	bool isInSWArea(QuadTreeNode* node);

	bool isInSEArea(QuadTreeNode* node);

	bool isInNWArea(QuadTreeNode* node);

	bool isInArea(QuadTreeNode* node);

	void notifyInsert(QuadTreeEntry* obj);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	void notifyDissapear(QuadTreeEntry* obj);

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	float getPreviousPositionX();

	float getPreviousPositionZ();

	float getPreviousPositionY();

	Vector3 getPosition();

	void setPosition(float x, float z, float y);

	void initializePosition(float x, float z, float y);

	int compareTo(QuadTreeEntry* obj);

	bool isInQuadTree();

	TransactionalReference<QuadTreeNode*> getNode();

	unsigned long long getDirtyObjectID();

	unsigned long long getObjectID();

	float getRadius();

	bool isBounding();

	void setNode(QuadTreeNode* n);

	void setBounding();

	void setRadius(float rad);

	void clearBounding();

	void setParent(QuadTreeEntry* par);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	QuadTreeEntry(DummyConstructorParameter* param);

	virtual ~QuadTreeEntry();

	int _compareTo(QuadTreeEntry* obj);

	unsigned long long _getDirtyObjectID();

	friend class QuadTreeEntryHelper;
};

} // namespace u3d
} // namespace util
} // namespace engine

using namespace engine::util::u3d;

namespace engine {
namespace util {
namespace u3d {

class QuadTreeEntryImplementation : public ObservableImplementation {
protected:
	Coordinate coordinates;

	Reference<QuadTreeNode* > node;

	bool bounding;

	ManagedWeakReference<QuadTreeEntry* > parent;

	Reference<CloseObjectsVector* > closeobjects;

	float radius;

public:
	QuadTreeEntryImplementation(QuadTreeNode* n = NULL);

	QuadTreeEntryImplementation(DummyConstructorParameter* param);

	void addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate = true);

	void removeInRangeObject(QuadTreeEntry* obj);

	void removeInRangeObject(int index);

	void removeInRangeObjects();

	virtual bool isInRange(QuadTreeEntry* obj, float range);

	bool isInRange(float x, float y, float range);

	float getDistanceTo(QuadTreeEntry* obj);

	SortedVector<ManagedReference<QuadTreeEntry* > >* getCloseObjects();

	ManagedWeakReference<QuadTreeEntry* > getParent();

	QuadTreeEntry* getParentUnsafe();

	QuadTreeEntry* getRootParentUnsafe();

	virtual bool containsPoint(float x, float y);

	ManagedWeakReference<QuadTreeEntry* > getRootParent();

	bool isInSWArea(QuadTreeNode* node);

	bool isInSEArea(QuadTreeNode* node);

	bool isInNWArea(QuadTreeNode* node);

	bool isInArea(QuadTreeNode* node);

	virtual void notifyInsert(QuadTreeEntry* obj);

	virtual void notifyPositionUpdate(QuadTreeEntry* obj);

	virtual void notifyDissapear(QuadTreeEntry* obj);

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	float getPreviousPositionX();

	float getPreviousPositionZ();

	float getPreviousPositionY();

	Vector3 getPosition();

	void setPosition(float x, float z, float y);

	void initializePosition(float x, float z, float y);

	virtual int compareTo(QuadTreeEntry* obj);

	bool isInQuadTree();

	TransactionalReference<QuadTreeNode*> getNode();

	virtual unsigned long long getDirtyObjectID();

	virtual unsigned long long getObjectID();

	float getRadius();

	bool isBounding();

	void setNode(QuadTreeNode* n);

	void setBounding();

	void setRadius(float rad);

	void clearBounding();

	virtual void setParent(QuadTreeEntry* par);

	WeakReference<QuadTreeEntry*> _this;

	operator const QuadTreeEntry*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~QuadTreeEntryImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class QuadTreeEntry;
};

class QuadTreeEntryAdapter : public ObservableAdapter {
public:
	QuadTreeEntryAdapter(QuadTreeEntry* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate);

	void removeInRangeObject(QuadTreeEntry* obj);

	void removeInRangeObject(int index);

	void removeInRangeObjects();

	bool isInRange(QuadTreeEntry* obj, float range);

	bool isInRange(float x, float y, float range);

	float getDistanceTo(QuadTreeEntry* obj);

	ManagedWeakReference<QuadTreeEntry* > getParent();

	QuadTreeEntry* getParentUnsafe();

	QuadTreeEntry* getRootParentUnsafe();

	bool containsPoint(float x, float y);

	ManagedWeakReference<QuadTreeEntry* > getRootParent();

	void notifyInsert(QuadTreeEntry* obj);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	void notifyDissapear(QuadTreeEntry* obj);

	float getPositionX();

	float getPositionZ();

	float getPositionY();

	float getPreviousPositionX();

	float getPreviousPositionZ();

	float getPreviousPositionY();

	void setPosition(float x, float z, float y);

	void initializePosition(float x, float z, float y);

	int compareTo(QuadTreeEntry* obj);

	bool isInQuadTree();

	unsigned long long getDirtyObjectID();

	unsigned long long getObjectID();

	float getRadius();

	bool isBounding();

	void setBounding();

	void setRadius(float rad);

	void clearBounding();

	void setParent(QuadTreeEntry* par);

};

class QuadTreeEntryHelper : public DistributedObjectClassHelper, public Singleton<QuadTreeEntryHelper> {
	static QuadTreeEntryHelper* staticInitializer;

public:
	QuadTreeEntryHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<QuadTreeEntryHelper>;
};

} // namespace u3d
} // namespace util
} // namespace engine

using namespace engine::util::u3d;

#endif /*QUADTREEENTRY_H_*/
