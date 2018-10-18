#ifndef LPMP_MULTIGRAPH_MATCHING_INPUT_H
#define LPMP_MULTIGRAPH_MATCHING_INPUT_H

#include "matching_problem_input.h"
#include <string>

namespace LPMP {

namespace Torresani_et_al_multigraph_matching_input {

    // file consists of multiple graph matching problems. Each graph matching section beings with
    // gm x y
    // where x and y are the graph numbers (0,...)
    // then comes the graph matching problem in Torresanit et al's format.

    multigraph_matching_input parse_file(const std::string& filename);
    multigraph_matching_input parse_string(const std::string& input);

}

}

#endif // LPMP_MULTIGRAPH_MATCHING_INPUT_H
