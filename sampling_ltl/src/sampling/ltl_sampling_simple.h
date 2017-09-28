#include "sampling/sample_space.h"
#include "sampling/region.h"
#include "trans_sys/spot_hoa_interpreter.h"
#include "trans_sys/buchi_automaton.h"

#include <lcm/lcm-cpp.hpp>
#include "lcmtypes/srcl_msgs.hpp"

using namespace srcl;

class LTL_SamplingSimple {
public:
    LTL_SamplingSimple(){};
    ~LTL_SamplingSimple(){};
private:
    double work_space_size_x_ = 100;
    double work_space_size_y_ = 100;
    std::string ltl_formula_;
    // std::vector<std::string> buchi_regions_;
    double EPSILON = 6;
    double RADIUS = 12;
    std::vector<std::vector<double>> path_;

    BAStruct ba_;
    SampleSpace all_space_;
    std::map<int, Region> all_interest_regions_;
    // lcm::LCM lcm;
    // int num_ba_;
    // std::vector<SubSampleSpace> sub_sample_space_;
    // std::map<int, SubSampleSpace> sample_space_ltl_map_;
    double get_dist(std::vector<double> states_1, std::vector<double> states_2);
    double fRand(double fMin, double fMax);
    std::vector<int> sample_from_ba(BAStruct buchi, SampleSpace &sample_space);
    void buchi_post (BAStruct &ba, std::vector<int> indep_set);
    bool if_in_region (std::vector<double> state, Region region);
    std::vector<double> step_from_to (SampleNode parent_sample, std::vector<double> sampled_state, double EPSILON);
    int step_from_to_buchi (int paraent_ba, std::vector<double> new_sample_state, BAStruct ba, std::map<int, Region> all_interest_regions);
    std::vector<double> sample_state (std::vector<int> ba_act);
public:
    void read_formula(std::string ltl_formula, std::vector<std::string> buchi_regions, std::vector<int> indep_set);
    void init_workspace(double work_space_size_x,double work_space_size_y);
    void set_interest_region(std::pair <double, double> position_x, std::pair <double, double> position_y, int interest_id);
    void set_init_state(std::vector<double> init_state);
    void start_sampling(int iteration);
    std::vector<std::vector<double>> get_path();

    // void read_region()
    // SubSampleSpace& get_sub_space(int num_ba);
    // void insert_sample(SampleNode new_sample, int sub_space_id);
    // uint64_t total_sample_num();

};