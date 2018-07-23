#include  "mpi.h"
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

 int rank, size;

 MPI::Init();

 MPI_Group group;

 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_group(MPI_COMM_WORLD, &group);
 MPI_Group_size(group, &size);

 if (rank == 0) {

  int broadcasts;
  MPI_Recv(&broadcasts, 1, MPI_INT, 0, 0, , MPI_STATUS_IGNORE);

  for (int i = 0; i < broadcasts; i++) {

   //Wait for signal to perform broadcast.
   //Perform broadcast. BUT NOT HERE!!!
  }
 }
 else {

  //Define behavior of remaining processes.
 }

 MPI_Finalize();
 return 0;
}
