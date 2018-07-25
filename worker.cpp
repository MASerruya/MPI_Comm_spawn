#include  "mpi.h"
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

 MPI::Init();

 MPI_Group group;
 MPI_Comm parent;
 int rank, size;

 //Obtaining parent communicator.
 MPI_Comm_get_parent(&parent);

 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_group(MPI_COMM_WORLD, &group);
 MPI_Group_size(group, &size);

 int broadcasts = (int) *argv[2], processes;

 for (int i = 0; i < broadcasts; i++)
 {
  sleep(5);
  MPI_Barrier(parent);
  //BROADCAST
  MPI_Bcast(&processes, 1, MPI_INT, 0, parent);
  std::cout << "Broadcast completed in slave " << rank << std::endl;

  if ((rank == (size-1)) && (i == 2)) {

   std::cout << "Process " << rank << " finalizing and returning." << std::endl << "It won't be available for following BROADCASTS!"; 
   MPI_Finalize();
   return 0;
  }
 }

 MPI_Finalize();
 return 0;
}
