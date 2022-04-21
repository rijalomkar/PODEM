#include "graph.h"
/***************************************************************************************************************************
 Main Function(Serial and Parallel Fault Simulation)
****************************************************************************************************************************/
int main(int argc,char **argv){
FILE *fisc,*fvec,*ffau,*fres;             //file pointers used for .isc file, .vec file, .faults file and resultfile
int Max,Opt,Npi,Npo,Total,Tfs;              //maxnode id,option,tot no of PIs,tot no of Pos,Tot no of input patterns& faults in.vec in.faults

NODE graph[Mnod];                         //structure used to store the ckt information in .isc file 
PATTERN vector[Mpt];  
OBJECTIVE back,OBJ,SAF;
LIST *dfrontier=NULL;
//SAF.gate=16;
//SAF.value=0;                    //structure used to store the input vectors information in .vec file 

//FAULT stuck[Mft];                      //structure used to store the faults information in .faults file
int i,j,a,b,c,d,SAline,line_count=0;  
float fault_cov;                           //random variables


//Read the .isc file and store the information in graph structure
fisc=fopen(argv[1],"r");                           //file pointer to open .isc file 
Max=0; 
Max=ReadIsc(fisc,graph);                 //read .isc file and return index of last node in graph formed
fclose(fisc); //close file pointer for .isc file
PrintCircuit(graph,Max);
//print all members of graph structure
//Read the .vec file and store the information in  vector structure
//fvec=fopen(argv[2],"r");
//Total=0;
//printf("\n\nPatterns::\n");
//Total=ReadVec(fvec,vector);
//fclose(fvec);
//Opt=0; 
//Opt=atoi(argv[3]);                          //getting the option from terminal for xval
fres=fopen(argv[2],"w"); 
count=0;
test=0;
for(i=1;i<=Max;i++){
	if(graph[i].Type==0) continue;
	for(j=0;j<2;j++){
		SAF.gate=i;
		SAF.value=j;
		start=clock();
		Podem(graph, Max, &dfrontier, SAF,fres);
		//printf("%f\n",1000*((double) (end - start)) / CLOCKS_PER_SEC);
		
	} line_count++;
}
SAline=line_count*2;
fprintf(fres,"TOTAL PATTERNS=%d\n",(SAline-(count+test)));
fprintf(fres,"Total No. of OUT OF TIME=%d\n",count);
fprintf(fres,"Total No. of UNTESTABLE FAULT=%d\n",test);
//printf("count=%d  test=%d",count,test);
fault_cov=(float)(SAline-(count+test))/SAline*100.0;
//printf("fault_cov=%f",fault_cov);
fprintf(fres,"FAULT COVERAGE=%.2f%%",fault_cov);
//printf("lineCount=%d\n",line_count);
fclose(fres); 			                       //file pointer to open .out file for printing results
//Perform Logic Simulation for each Input vector and print the Pos .val in output file   
//printf("\nOutputs::\n");
//LogicSimulation(graph,vector,Total,Max,fres);
/*ResetCircuit (graph,Max);
GetObjective(graph,0,16,&dfrontier,&OBJ);
printf("objvalue=%d\nobjgate=%d\n",OBJ.value,OBJ.gate);
Backtrace(graph,OBJ.gate,OBJ.value,&back);
printf("gatevalue=%d\ngate_number=%d\n",back.value, back.gate);
LogicImplication(graph,Max,back.value,back.gate,&dfrontier,&SAF);

GetObjective(graph,0,16,&dfrontier,&OBJ);
printf("objvalue=%d\nobjgate=%d\n",OBJ.value,OBJ.gate);
Backtrace(graph,OBJ.gate,OBJ.value,&back);
printf("gatevalue=%d\ngate_number=%d\n",back.value, back.gate);
LogicImplication(graph,Max,back.value,back.gate,&dfrontier,&SAF);

/*GetObjective(graph,0,19,&dfrontier,&OBJ);
printf("objvalue=%d\nobjgate=%d\n",OBJ.value,OBJ.gate);
Backtrace(graph,OBJ.gate,OBJ.value,&back);
printf("gatevalue=%d\ngate_number=%d\n",back.value, back.gate);
LogicImplication(graph,Max,back.value,back.gate,&dfrontier,&SAF);

printf("D-frontier=");
PrintList(dfrontier);
printf("\n");
OBJ.value=0;
OBJ.gate=0;
printf("Result from objective=%d",GetObjective(graph,0,19,&dfrontier,&OBJ));
PrintCircuit(graph,Max);
*/
//SetNodeOutput(&fres, graph, Max, vector, Total);
                                                 //close file pointer for .out file

ClearCircuit(graph,Mnod);                                      //clear memeory for all members of graph
//for(a=0;a<Total;a++){ bzero(vector[a].piv,Mpi); }                //clear memeory for all members of vector
return 0;
}//end of main
/****************************************************************************************************************************/

