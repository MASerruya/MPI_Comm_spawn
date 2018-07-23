#include "mpi.h"
#include <unistd.h>

int main (int argc, char* argv[]) {

 MPI_Init(&argc, &argv);

 int limit = argv[2], processes, universe, flag, size1, size2;

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
 //Execute 'worker' and pass as argument the number of broadcasts to be done.
 MPI_Comm_spawn(argv[1], argv[2], processes, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &intercomm, MPI_ERRCODES_IGNORE);

 MPI_Comm_remote_size(intercomm, &size2);
 MPI_Comm_group(MPI_COMM_WORLD, &group);
 std::cout << "PROCESSES CREATED: " << size2 <<". Master processes: " <<  size1 << ". Group: " << group << std::endl;

 for (int i = 0; i < limit; i++) 
 {
  sleep(5);
  std::cout << "Prepare for broadcast!" << std::endl;
  MPI_Barrier(intercomm);
  //BROADCAST
  MPI_Bcast(&processes, 1, MPI_INT, 0, intercomm);
  std::cout << "Broadcats completed in master." << std::endl;
 }

 MPI_Finalize();

 return 0;
}
