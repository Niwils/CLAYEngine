/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/production/ProcessStep.h
 *
 * \brief A ProcessStep is a production step executed by an ItemProcessor.
 * 	A ProcessStep has a unique process ID, with a list of required items if
 * 	assembly is required.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#include <Types.h>
#include <ObjList.h>

class ProcessStep
{
public:
	ProcessStep(s_gameElementUUID _processID);
	~ProcessStep();

	void addRawItem(s_gameElementUUID _itemTypeID);

	ObjList<s_gameElementUUID> *getRawMaterialsList();

private:
	ObjList<s_gameElementUUID> *m_RawMaterials;
};
