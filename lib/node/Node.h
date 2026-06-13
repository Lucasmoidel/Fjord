#ifndef Node_H
#define Node_H

#include "../Fjord.h"

class Node { // game engine that will provide functions    
    public:
        Node(int xVar=0, int yVar=0, int xSize=1, int ySize=1, std::string name = "Node2D");

        void addChild(Node* node);

        std::string name = "NONAME";
        std::string id = "NOID";
        Transform transform;
        std::string type;

        Node* parent = NULL;

        std::vector<Node*> children;

        virtual void update_node_position();

        virtual void Update(){}; // Definition of Update Function. Called once every frame
        virtual void Input(){}; // Definition of Input Function. Called once very frame.
        virtual void Render(){};
        
        // Transform Functions

        void rotate(float degrees);

        // Dealing with Children
        std::vector<Node*> get_children();
        int get_children_count();
        Node* get_node(std::string path);
        void kill_child(std::string namein);

        template <typename T> T* createNode(int xPos, int yPos, int xSize, int ySize, std::string name){
            T* node = new T(xPos, yPos, xSize, ySize, name);
            //engine.nodes.push_back(node);
            //children.push_back(node);
            node->parent = this;
            return node;
        }

        // Improvement: This function should be protected
        void _engine_update_node(); // used as alternative for render so render may be overridden
};

#endif // MYHEADER_H