#include  "mpi.h"
#include <unistd.h>
#include <stdlib.h>

int main () {

 int rank, size;

 MPI::Init();

 MPI_Group group;

 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_group(MPI_COMM_WORLD, &group);
 MPI_Group_size(group, &size);


 for (int i = 0; i < 3; i++)
 {
  std::cout << " Process " << rank << " of " << size << " breathing. Group: " << group << std::endl;
  sleep(3);
  /*if (rank == 0) sleep(10);
  else {
   MPI_Group_free(&group);
   MPI_Finalize(); 
   return 0;
  }*/
 }

 MPI_Finalize();
 return 0;
}
