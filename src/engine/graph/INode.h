/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/graph/INode.h
 *
 * \brief An INode object is a node object of a graph.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#ifndef _ENGINE_GRAPH_INODE_H
#define _ENGINE_GRAPH_INODE_H
#include <IToken.h>
#include <ObjList.h>
#include <HashHeap.h>
#include <IGraphElement.h>

class INode : public IGraphElement
{
public:
	INode(s_GraphElementUUID _uuid);
	virtual ~INode() = 0;

	void setToken(IToken *_token);

	IToken *getToken();

	void setInput(IGraphElement *_input);

	IGraphElement *getInput();

	void addOutput(IGraphElement *_output);

	ObjList<IGraphElement> *getOutputs();

protected:
	IToken *m_CarriedToken;

	IGraphElement *m_Input;

	ObjList<IGraphElement> *m_Outputs;
};

#endif /* End _ENGINE_GRAPH_INODE_H */
