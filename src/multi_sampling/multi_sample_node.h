// #ifndef SRC_SAMPLE_NODE_H_
// #define SRC_SAMPLE_NODE_H_
#include <map>
#include <vector>
#include <utility>
#include "trajectory/dubins_steer.h"
#include "sampling/region.h"


class MultiSampleNode {
public:
    MultiSampleNode(){};
    MultiSampleNode(uint64_t id);
    ~MultiSampleNode(){};

private:
    std::vector<double> state_;
    std::vector<std::vector<double>> all_state_;
    std::map<int, std::vector<double>> all_state_map_;
    uint64_t id_;
    int ba_state_;
    double cost_;
    uint64_t parent_id_;
    int parent_ba_;
    std::vector<std::pair<int, uint64_t>> children_;
    std::vector<std::vector<std::vector<double>>> multi_traj_point_wise_;
    // std::vector<std::vector<std::vector<double>>> all_traj_point_wise_;
    std::map<int, std::vector<std::vector<double>>> all_traj_point_wise_map_;
    std::vector<DubinsPath::PathData> traj_data_;

public:
    std::vector<double> get_state();
    std::vector<std::vector<double>> get_all_states();
    std::map<int, std::vector<double>> get_all_state_map();

    void set_all_states(std::vector<std::vector<double>> all_states);

    void set_state(std::vector<double> state);

    uint64_t get_id();
    void set_id(uint64_t id);

    int get_ba();
    void set_ba(int ba_id);

    double get_cost();
    void set_cost(double cost);

    uint64_t get_parent_id();
    void set_parent_id(uint64_t parent_id);

    int get_parent_ba();
    void set_parent_ba(int parent_ba);
    
    std::vector<std::vector<std::vector<double>>> get_multi_traj();
    void set_multi_traj(std::vector<std::vector<std::vector<double>>> multi_traj);

    void set_traj_data(std::vector<DubinsPath::PathData> traj_data);
    std::vector<DubinsPath::PathData> get_traj_data();

    std::vector<std::pair<int, uint64_t>>& get_children_id();
    void set_children_id(std::vector<std::pair<int, uint64_t>> children);
    void add_children_id(std::pair<int, uint64_t> one_children);

};


class SubSampleSpace {
public:
    SubSampleSpace(){};
    ~SubSampleSpace(){};
private:
    std::vector<MultiSampleNode> sample_nodes_;
    int ba_state_;
    std::map<int, MultiSampleNode> sample_node_id_map_; 
    double get_dist(std::vector<double> states_1, std::vector<double> states_2);
    double get_dist(MultiSampleNode multi_sample_1, MultiSampleNode multi_sample_2);
    double get_dist(std::vector<std::vector<double>> states_1, std::vector<std::vector<double>> states_2);
    double get_dist_dubins(std::vector<double> states_1, std::vector<double> states_2, double min_radius);
    double get_dist_dubins(std::vector<std::vector<double>> states_1, std::vector<std::vector<double>> states_2, double min_radius);
public:
    void insert_sample(MultiSampleNode new_sample);
    MultiSampleNode& get_sample(uint64_t id);
    std::vector<MultiSampleNode>& get_all_samples();
    MultiSampleNode& get_min_cost_sample();
    int num_samples();
    int get_ba_state();
    MultiSampleNode& get_parent(std::vector<double> state);
    MultiSampleNode& get_parent(MultiSampleNode multi_sample);
    MultiSampleNode& get_parent(std::vector<std::vector<double>> multi_states);
    MultiSampleNode& get_parent_dubins(std::vector<double> state, double min_radius);
    MultiSampleNode& get_parent_dubins(std::vector<std::vector<double>> multi_states, double min_radius);
    MultiSampleNode& rechoose_parent(MultiSampleNode parent_sample, std::vector<std::vector<double>> all_states, std::vector<Region> obstacles, double RADIUS);
    MultiSampleNode& rechoose_parent_dubins(MultiSampleNode parent_sample, std::vector<std::vector<double>> all_states, std::vector<DubinsPath::PathData>& multi_dubins_steer_data, std::vector<Region> obstacles, double work_space_size_x, double work_space_size_y, double RADIUS, double min_radius, double path_step, double collision_check_rate);

};
