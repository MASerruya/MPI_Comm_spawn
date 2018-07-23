#include  "mpi.h"
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

 MPI::Init();

 MPI_Group group;
 MPI_Comm parent;
 int rank, size;

 //Obtaining parent communicator.
 MPI_Comm_get_parent(&parent;);

 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_group(MPI_COMM_WORLD, &group);
 MPI_Group_size(group, &size);

 int broadcasts = argv[1];

 for (int i = 0; i < broadcasts; i++) {

  MPI_Barrier(parent);
  //BROADCAST

  if (rank == (size-1)) {

   std::cout << "Process " << rank << " finalizing and returning." << std::endl << "It won't be available for following BROADCASTS!"; 
   MPI_Finalize();
   return 0;
  }
 }

 MPI_Finalize();
 return 0;
}
