// --- Point-to-point communication with MPI ---
//
// The below skeleton of an MPI program initializes MPI, retrieves the rank ID of the process that 
// runs the specific copy of the program as well as the number of processes the program is executed with. 
// Afterwards, it prints a message to the screen.
// 
// a) Compile and run the code on NCC via the provided sbatch script "run_mpi_program.sh".
//      1. Login to NCC: 
//          ssh your-user-name@mira.dur.ac.uk 
//          ssh your-user-name@ncc1.clients.dur.ac.uk 
//      2. Submit the job script to the workload manager slurm:
//          sbatch run_mpi_program.sh
// b) Extend the program such that rank 0 sends the message to rank 1 for printing via MPI_Send and MPI_Recv.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <mpi.h>

int main(int argc, char** argv) {

    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int num_ranks;
    MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);
    

    if (rank == 0) {
        char message[] = "Hello World!\n";
        MPI_Send(&message, 14, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("Rank 0 has sent a message to Rank 1\n");
    } else if (rank == 1) {
        char message[64];
        //
        MPI_Recv(&message, 14, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank 1 has received a message from Rank 0:\n%s",message);
    }
    
    MPI_Finalize();
}
