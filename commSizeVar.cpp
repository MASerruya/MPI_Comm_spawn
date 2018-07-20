#include "mpi.h"
#include <unistd.h>

int main (int argc, char* argv[]) {

 int size1, size2;

 MPI_Init(&argc, &argv);

 int limit = 1, processes;

 MPI_Comm intercomm[limit];
 MPI_Group group;

 for (int i = 0; i < limit; i++) 
 {

  MPI_Comm_size(MPI_COMM_WORLD, &size2);
  processes = MPI_UNIVERSE_SIZE - size2;

  std::cout << "LAUNCHING NEW PROCESSES!" << std::endl;
  MPI_Comm_spawn(argv[1], MPI_ARGV_NULL, processes, MPI::INFO_NULL, 0, MPI_COMM_WORLD, &intercomm[i], MPI_ERRCODES_IGNORE);

  MPI_Comm_remote_size(intercomm[i], &size1);
  MPI_Comm_group(MPI_COMM_WORLD, &group);
  std::cout << "PROCESSES CREATED: " << size1 <<". Master processes: " <<  size2 << ". Group: " << group << std::endl;
 }

 /*sleep(50);
 MPI_Comm_remote_size(intercomm[0], &size1);
 std::cout << size1 << std::endl;
 //}*/

 MPI_Finalize();

 return 0;
}
