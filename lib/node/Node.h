#ifndef Node_H
#define Node_H

#include "../Fjord.h"

class Node { // game engine that will provide functions    
    public:
        Node(int xVar=0, int yVar=0, int xSize=1, int ySize=1, std::string name = "Node2D");

        std::string name = "NONAME";
        std::string id = "NOID";
        Transform transform;
        std::string type;

        Node* parent = NULL;

        std::vector<Node*> children;

        void update_node_position();

        virtual void Update(){}; // Definition of Update Function. Called once every frame
        virtual void Input(){}; // Definition of Input Function. Called once very frame.
        virtual void Render(RendererGL* renderer);
        SDL_Rect rect;
        
        // Children operations
        std::vector<Node*> get_children();
        int get_children_count();
        Node* get_node(std::string path);
        void kill_child(std::string namein, int killall = 0);

        template <typename T, typename... Types> T* createNode(Types... args){
            T* node = new T(args...);
            //engine.nodes.push_back(node);
            children.push_back(node);
            node->parent = this;
            return node;
        }
};

#endif // MYHEADER_H