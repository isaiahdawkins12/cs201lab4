// rchaney@pdx.edu

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "push_pop.h"

// The valid commands:
//   status
//   push $val
//   push %reg
//   pop %reg

// a couple global variables
int is_verbose = 0;
FILE *ofile = NULL;

static unsigned long stack_bot = DEF_STACK_BOT; // the high address for the stack
static unsigned long stack_limit = DEF_STACK_LIMIT; // the low address for the stack
static unsigned long rsp = DEF_RSP; // the initial value for the rsp register
static unsigned long *stack = NULL; // points to the bytes for the stack
static unsigned long registers[REG_RDX + 1] = { // the general purpose registers
    // These are just some default values.
    REG_RAX + 20
    , REG_RBX + 30
    , REG_RCX + 40
    , REG_RDX + 50
};

// These intentionally look like the assembly language calls. They access other
// variables in the same way the assembly language calls access other resources,
// such as registers and the address space.
static void pop(char *);
static void push_reg(char *);
static void push_value(char *);

static void
pop(char *reg)
{
#error stuff goes in here
}

static void
push_reg(char *reg)
{
	
#error stuff goes in here
}

static void
push_value(char *reg)
{
#error stuff goes in here
}

int
main(int argc, char *argv[])
{
    FILE *ifile = stdin;

    ofile = stdout;
    {
        int opt = 0;
        int res_count = 0;

        // Do not begin processing input until AFTER you have completely
        // processed the command line using getopt() .

        while ((opt = getopt(argc, argv, GETOPT_STRING)) != -1) {
            switch (opt) {

                // Do not begin processing input until AFTER you have completely
                // processed the command line using getopt() .

#error stuff goes in here
			case 'i':
				// opening file to read input from
				file_name = optarg;
				ifile = fopen(file_name, "r");		// ifile is a pointer to the structure file
				if (ifile == NULL) {
					fprintf(stderr, " could not open file: %s\n", file_name);	// fprintf specifically for files
					exit(EXIT_FAILURE);
				}
				// function here that reads in?
				break;			
			case 'o':
				// opening file to write out to
				file_name = optarg;
				ofile = fopen(file_name, "w");		// ofile is a ptr to the structure file
				if (ofile == NULL) {
					fprintf(stderr, " could not open file: %s\n", file_name);
					exit(EXIT_FAILURE);
				}
				// function here that writes out?
				break;
			case 'b':
				if (optarg % 8 != 0){
					printf(stderr, "Not divisible by 8\n");	
				}
			case 'l':
			
			case 's':
	
            case 'v':
                is_verbose++;
                break;
            case 'h':
                printf("%s\n\toptions: %s\n", argv[0], GETOPT_STRING);
                printf("\ti: name of input file\n");
                printf("\to: name of output file\n");
                printf("\tb: stack_bottom (high address, as hex)\n");
                printf("\tl: stack limit (low address, as hex)\n");
                printf("\ts: beginning %%rsp value (within the stack, as hex)\n");
                printf("\tv  verbose output\n");
                printf("\th  help\n");

                exit(EXIT_SUCCESS);
                break;
            default:
                break;
            }
        }
    }
    
    // Do not begin processing input until AFTER you have completely
    // processed the command line using the getopt() loop.

    // Do all the validation of upper and lower bounds down here, NOT
    // within the getopt() loop.
    
#error lots of stuff goes in here

    // Have your loop for processing all the input down here.
    
    return EXIT_SUCCESS;
}
