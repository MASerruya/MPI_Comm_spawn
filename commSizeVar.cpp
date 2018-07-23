#include "mpi.h"
#include <unistd.h>

int main (int argc, char* argv[]) {

 MPI_Init(&argc, &argv);

 int limit = 3, processes, universe, flag, size1, size2;

 MPI_Comm intercomm;
 MPI_Group group;

 MPI_Comm_size(MPI_COMM_WORLD, &size1);
 MPI_Comm_get_attr(MPI_COMM_WORLD, MPI_UNIVERSE_SIZE, &universe, &flag);

 if (!flag) {

  std::cout << "No support for UNIVERSE_SIZE." << std::endl << "Number of processes to be thrown?" << endl; 
  std::cin >> processes;
 }
 else processes = universe - size1;

 std::cout << "LAUNCHING NEW PROCESSES!" << std::endl;
 MPI_Comm_spawn(argv[1], MPI_ARGV_NULL, processes, MPI::INFO_NULL, 0, MPI_COMM_WORLD, &intercomm, MPI_ERRCODES_IGNORE);

 MPI_Comm_remote_size(intercomm, &size2);
 MPI_Comm_group(MPI_COMM_WORLD, &group);
 std::cout << "PROCESSES CREATED: " << size2 <<". Master processes: " <<  size1 << ". Group: " << group << std::endl;

 //Send number of broadcasts to be done.

 for (int i = 0; i < limit; i++) 
 {

  std::cout << "Prepare for broadcast!" << std::endl;
  //Send signal to perform broadcast.
 }

 MPI_Finalize();

 return 0;
}
