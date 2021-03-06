
#include "horizon_tracking/horizon_tracking.h"
#include "horizon_tracking/horizon_tracking_primal_rounding.hxx"
#include "visitors/standard_visitor.hxx"
#include "LP.h"
#include "LP_FWMAP.hxx"
using namespace LPMP;
int main(int argc, char** argv) {
Solver<LP_tree_FWMAP<FMC_HORIZON_TRACKING_MULTIPLE_CHAINS>,StandardVisitor> solver(argc,argv);
auto input = horizon_tracking_uai_input::parse_file(solver.get_input_file());
construct_horizon_tracking_problem_on_grid_to_chains(input, solver, solver.GetProblemConstructor());
solver.Solve();
solver.GetLP().write_back_reparametrization();
round_primal_solution(solver);
solver.WritePrimal();
std::cout<<"\n\n Primal Cost: "<<solver.primal_cost();
std::cout<<"\n Percentage duality gap: "<<100.0 * (solver.primal_cost() - solver.lower_bound()) / solver.lower_bound() <<"\%\n\n";
}