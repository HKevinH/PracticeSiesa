
#include "pch.h"
#include <iostream>
#include <vector>
#include <memory>

class Node {
public: 
	int weight; //Size Node
	std::vector<std::unique_ptr<Node>> children;  //Children Node

	//Constructor
	Node(int weight) : weight(weight) {}

	void add_child(std::unique_ptr<Node> child) {
		children.push_back(std::move(child));
	}

	int get_weight() {
		int total = weight;
		for (auto &child : children) {
			total += child->get_weight();
		}
		return total;
	}


	int total_nodes() {
		int count = 1; // Contar este nodo
		for (auto& child : children) {
			count += child->total_nodes();
		}
		return count;
	}

	float average_weight() {
		int total_wt = get_weight();
		int count = total_nodes();
		return static_cast<float>(total_wt) / count;
	}

	int get_height() {
		int max_height = 0;
		for (auto& child : children) {
			max_height = std::max(max_height, child->get_height());
		}
		return 1 + max_height;
	}
};

//Create Tree Multiple Nodes
inline std::unique_ptr<Node> create_tree() {
	auto root = std::make_unique<Node>(10); //Root Node Size 10
	root->add_child(std::make_unique<Node>(25)); //Child Node Size 5
	root->add_child(std::make_unique<Node>(15)); //Child Node Size 15
	root->add_child(std::make_unique<Node>(20)); //Child Node Size 20

	root->children[0]->add_child(std::make_unique<Node>(5)); //Child Node Size 5
	return root;
}	