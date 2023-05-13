// rchaney@pdx.edu
// $RCSfile: stack_status.c,v $ $Revision: 1.11 $

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "push_pop.h"

void
stack_status(unsigned long *stack, unsigned long *registers, unsigned long rsp
             , unsigned long stack_bot, unsigned long stack_limit, FILE *ofile)
{
    char reg_name[] = "%r?x";

    if (stack == NULL) {
        fprintf(stderr, "Stack is NULL, cannot display\n");
        assert(stack);
        return;
    }
    if (ofile == NULL) {
        fprintf(stderr, "ofile not set, cannot display\n");
        assert(ofile);
        return;
    }
    fprintf(ofile, "register_values:\n");
    fprintf(ofile, "\t%3s:\t\t0x%08lx\n", "%rsp", rsp);
    for(int i = REG_RAX; i <= REG_RDX; i++) {
        reg_name[2] = 'a' + i;
        fprintf(ofile, "\t%3s:\t\t0x%08lx\n", reg_name, registers[i]);
    }

    fprintf(ofile, "stack:\n\taddress\t\tvalue\n");
    for(unsigned long i = stack_bot, j = 0; i >= stack_limit; i -= REG_SIZE, j++) {
        fprintf(ofile, "%s\t0x%08lx\t0x%08lx\n"
                , i == rsp ? ">" : ""
                , i
                , stack[j]);
    }
    
    fprintf(ofile, "\n");
}
