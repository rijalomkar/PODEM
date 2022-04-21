#include "graph.h"

    //truth table of gates
    int and[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,2,2,2},{0,3,2,3,0},{0,4,2,0,4}};
    int or[5][5]={{0,1,2,3,4},{1,1,1,1,1},{2,1,2,2,2},{3,1,2,3,1},{4,1,2,1,4}};
    int xor[3][3]={{0,1,2},{1,0,2},{2,2,2}};
    int not[5]={1,0,2,4,3};
    int from[5]={0,1,2,3,4};
    int NonControlling[11]={0,0,1,1,0,0,0,0,0,0,0};

    int ReadVec(FILE *fvec,PATTERN *vector){
        int i,j,a=0,n;
        char line[Mlin];
        //printf("hello readvec");
        //getchar();
        j=0;
        while(!feof(fvec)){
            fgets(line, Mlin+1, fvec);
            a=strlen(line);
            for(i=0;i<a;i++){
                //printf("line=%d\n", a);
                if( line[i]=='0')           vector[j].vector[i]=0;
                else if(line[i]=='1')       vector[j].vector[i]=1;
                else if(line[i]=='x'||'X')  vector[j].vector[i]=2;
            }
            j++;
        }
        for(i=0;i<j;i++){
           for(n=0;n<a;n++)
            printf("%d",vector[i].vector[n]);
            printf("\n");
        }
        return j;
    }  

/*    void LogicSimulation(NODE *graph, PATTERN *pattern, int Patterns, int TotalGate, FILE *result){*/
/*        LIST *temp;*/
/*        int i,j,count;*/
/*        int x=0,y=0;*/
/*        for(j=0;j<Patterns;j++){*/
/*            count=0;*/
/*            for(i=0;i<=TotalGate;i++){*/
/*                if(graph[i].Type==INPT){*/
/*                        graph[i].Cval=pattern[j].vector[count];*/
/*                        //printf("INPT=%d",graph[i].Cval);*/
/*                        count++;*/
/*                }*/
/*                else if(graph[i].Type==FROM){*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                                graph[i].Cval=from[x];*/
/*                                //printf("%d",graph[i].Cval);*/
/*                                temp=temp->next;*/
/*                        }*/
/*                }*/
/*                else if(graph[i].Type==BUFF){*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                                graph[i].Cval=graph[temp->id].Cval;*/
/*                                temp=temp->next;*/
/*                        }*/
/*                }*/
/*                else if(graph[i].Type==AND){*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            if(temp->next!=NULL){*/
/*                                y=graph[temp->next->id].Cval;*/
/*                                graph[i].Cval=and[x][y];*/
/*                                x=graph[i].Cval;*/
/*                            }*/
/*                            temp=temp->next;*/
/*                        }*/
/*                }*/
/*                else if(graph[i].Type==OR){*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            if(temp->next!=NULL){*/
/*                                y=graph[temp->next->id].Cval;*/
/*                                graph[i].Cval=or[x][y];*/
/*                                x=graph[i].Cval;*/
/*                            }*/
/*                            temp=temp->next;*/
/*                        }*/
/*                    }*/
/*                else if (graph[i].Type==NOT){*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            graph[i].Cval=not[x];*/
/*                            temp=temp->next;*/
/*                        }*/
/*                    }*/
/*                else if (graph[i].Type==NAND){*/
/*                        //int a=0;*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            if(temp->next!=NULL){*/
/*                                y=graph[temp->next->id].Cval;*/
/*                                graph[i].Cval=and[x][y];*/
/*                                x=graph[i].Cval;*/
/*                               */
/*                            }*/
/*                            temp=temp->next;*/
/*                        }graph[i].Cval=not[x];*/
/*                    }*/
/*                 else if (graph[i].Type==NOR){*/
/*                        //int a=0;*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            if(temp->next!=NULL){*/
/*                                y=graph[temp->next->id].Cval;*/
/*                                graph[i].Cval=or[x][y];*/
/*                                x=graph[i].Cval; */
/*                            }*/
/*                            temp=temp->next;*/
/*                        }   graph[i].Cval=not[graph[i].Cval];*/
/*                    }*/
/*                else if (graph[i].Type==XOR){*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            if(temp->next!=NULL){*/
/*                                y=graph[temp->next->id].Cval;*/
/*                                graph[i].Cval=xor[x][y];*/
/*                                x=graph[i].Cval; */
/*                            }*/
/*                            temp=temp->next;*/
/*                        }*/
/*                    }*/
/*                else if (graph[i].Type==XNOR){*/
/*                        int a=0;*/
/*                        temp=graph[i].Fin;*/
/*                        x=graph[temp->id].Cval;*/
/*                        while(temp!=NULL){*/
/*                            if(temp->next!=NULL){*/
/*                                y=graph[temp->next->id].Cval;*/
/*                                a=xor[x][y];*/
/*                                x=graph[i].Cval; */
/*                            }*/
/*                            temp=temp->next;*/
/*                        }     graph[i].Cval=not[a];*/
/*                    }else{};*/
/*                if(graph[i].Po == 1){*/
/*                    printf("%d",graph[i].Cval);				*/
/*                    putc(graph[i].Cval, result);*/
/*                }*/
/*            }printf("\n");*/
/*                putc('\n', result);*/
/*        }*/
/*            */
/*    }*/
    void ResetCircuit (NODE *graph, int TotalGat){
        int i;
        for (i=0;i<=TotalGat;i++){
            graph[i].Cval=2;
        }
    }
   OBJECTIVE Backtrace(NODE *graph,int g, int v){
	OBJECTIVE input;        
	int num_inversion=0,PreVal;
        LIST *temp;
	if (graph[g].Type==NAND || graph[g].Type==NOT || graph[g].Type==NOR) num_inversion++;
        while(graph[g].Type!=INPT){
		PreVal=g;
            temp=graph[g].Fin;
            while(temp!=NULL){
			if(graph[temp->id].Cval==2){               
     				g=temp->id;
					break;
			}
			temp=temp->next;
             }
	
		if (graph[g].Type==NAND || graph[g].Type==NOT || graph[g].Type==NOR) num_inversion++;
/*		printf("g=%d",g); getchar();*/
		if(g==PreVal){
			input.value=0;
			input.gate=0;
			return input;
		}
        }
        if (num_inversion % 2!=0){
            v=not[v];
        }
        input.value =v;
        input.gate =g;
	return input;
    }

	int LogicImplication (NODE *graph, int TotalGat, int value, int gate, LIST **dfrontier,OBJECTIVE SAF){
		int i, status=SUCCESS,preCval;
		LIST *temp,*Nlist=NULL;	
		int x=0,y=0;
		//*f_detected=FAILURE;	
		graph[gate].Cval=value;
		if(FaultInjection(graph,SAF,gate)==FAILURE) status=FAILURE;
		UpdateNlist(graph[gate].Fot,&Nlist);		
		while(Nlist!=NULL){
			i=Nlist->id;
			preCval=graph[i].Cval;
			if(graph[i].Type==FROM){
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                        graph[i].Cval=from[x];
		                        temp=temp->next;
		                }
		      	}
		      	else if(graph[i].Type==BUFF){
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                        graph[i].Cval=graph[temp->id].Cval;
		                        temp=temp->next;
		                }
		        }
		        else if(graph[i].Type==AND){
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    if(temp->next!=NULL){
		                        y=graph[temp->next->id].Cval;
		                        graph[i].Cval=and[x][y];
		                        x=graph[i].Cval;
		                    }
		                    temp=temp->next;
		                }
		        }
		        else if(graph[i].Type==OR){
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    if(temp->next!=NULL){
		                        y=graph[temp->next->id].Cval;
		                        graph[i].Cval=or[x][y];
		                        x=graph[i].Cval;
		                    }
		                    temp=temp->next;
		                }
		        }
		        else if (graph[i].Type==NOT){
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    graph[i].Cval=not[x];
		                    temp=temp->next;
		                }
		         }
		        else if (graph[i].Type==NAND){
		                //int a=0;
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    if(temp->next!=NULL){
		                        y=graph[temp->next->id].Cval;
		                        graph[i].Cval=and[x][y];
		                        x=graph[i].Cval;
		                       
		                    }
		                    temp=temp->next;
		                }graph[i].Cval=not[x];
		       	}
		        else if (graph[i].Type==NOR){
		                //int a=0;
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    if(temp->next!=NULL){
		                        y=graph[temp->next->id].Cval;
		                        graph[i].Cval=or[x][y];
		                        x=graph[i].Cval; 
		                    }
		                    temp=temp->next;
		                }   graph[i].Cval=not[graph[i].Cval];
		        }
		        else if (graph[i].Type==XOR){
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    if(temp->next!=NULL){
		                        y=graph[temp->next->id].Cval;
		                        graph[i].Cval=xor[x][y];
		                        x=graph[i].Cval; 
		                    }
		                    temp=temp->next;
		                }
		        }
		        else if (graph[i].Type==XNOR){
		                int a=0;
		                temp=graph[i].Fin;
		                x=graph[temp->id].Cval;
		                while(temp!=NULL){
		                    if(temp->next!=NULL){
		                        y=graph[temp->next->id].Cval;
		                        a=xor[x][y];
		                        x=graph[i].Cval; 
		                    }
		                    temp=temp->next;
		                }     graph[i].Cval=not[a];
		        }
			else{};
			if(FaultInjection(graph,SAF,i)==FAILURE) status=FAILURE;
			if(CheckDfrontier(graph, i)) InsertList(dfrontier, i);
			if(preCval!=graph[i].Cval) UpdateNlist(graph[i].Fot,&Nlist);
			//printf("%d--",i); getchar();	
			DeleteEle(&Nlist,i);
		
       		} 
		return status;    
    }
	void UpdateNlist(LIST *Fot,LIST **Nlist){
		while(Fot!=NULL){
			InsertList(Nlist,Fot->id); 
			Fot=Fot->next;
		}
	}

	int FaultInjection(NODE *graph, OBJECTIVE SAF,int g){
		if(g==SAF.gate){
			if(SAF.value==not[graph[SAF.gate].Cval])
				graph[SAF.gate].Cval=3+SAF.value;
			else if(SAF.value==graph[SAF.gate].Cval)
				return FAILURE;
		}
		return SUCCESS;
	}	
	int GetObjective(NODE *graph,OBJECTIVE SAF,OBJECTIVE *OBJ,LIST **dfrontier){
		//OBJECTIVE OBJ;
		int d;
		LIST *fin;
		//printf("%d",graph[SAF.gate].Cval); getchar();
		if( graph[SAF.gate].Cval!=3 && graph[SAF.gate].Cval!=4){
		    OBJ->gate=SAF.gate;
		    OBJ->value=not[SAF.value];
		    //printf("xx%dxx%d\n",OBJ->gate,OBJ->value);
			return SUCCESS;
		}
		if(*dfrontier==NULL) return FAILURE;
		d =(*dfrontier)->id; //getting the ID of D-frontier
		while(!CheckDfrontier(graph,d) && *dfrontier!=NULL)		//double checking the validity of d-frontier
			d=RemoveDfrontier(graph, dfrontier);
			
		if(*dfrontier!=NULL){
			fin=graph[d].Fin;
			while(fin!=NULL){
				if(graph[fin->id].Cval==2) 
					break;
				fin=fin->next;
			}
			if(fin!=NULL){
				OBJ->gate=fin->id; //one of the fan_in of d-frontier
				OBJ->value=NonControlling[graph[fin->id].Type]; //non_controlling value of that fan_in of d-frontier with value X
				//printf("xx%dxx%d\n",OBJ->gate,OBJ->value);
				return SUCCESS;
			}
			else{
				printf("ERROR:INVALID D-FRONTIER");
				exit (0);
			}
		}
		else{
			return FAILURE;
		}
		return SUCCESS;	
	}
	
	int CheckDfrontier(NODE *graph, int i){
		LIST *temp;
		if(graph[i].Cval==2){
			temp=graph[i].Fin;
			while(temp!=NULL){
				if(graph[temp->id].Cval==3 || graph[temp->id].Cval==4)
					return SUCCESS;
				temp=temp->next;
			}
		}
		return FAILURE;
	}
			
	int RemoveDfrontier(NODE *graph, LIST **dfrontier){
		int d=0;
		d =(*dfrontier)->id;
		DeleteEle(dfrontier,d);
		if(*dfrontier==NULL) return FAILURE;	
		return (*dfrontier)->id;
	}
		
	int Podem_Recursion(NODE *graph, int TotalGat, LIST **dfrontier, OBJECTIVE SAF){
		int i,result,from_imply1,state;
		int f_detect;	
		OBJECTIVE FROM_OBJ, BACK;
		end = clock();
    	cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
		if(cpu_time > 0.2) return TIME_LIMIT_EXCEEDED;

		for(i=1;i<=TotalGat;i++){
			if(graph[i].Po==1){
				if(graph[i].Cval==3 || graph[i].Cval==4)
					return SUCCESS;
			}
		}
		state = GetObjective(graph,SAF,&FROM_OBJ,dfrontier);
		
		if(state==FAILURE)	return FAILURE;
		
		BACK= Backtrace(graph,FROM_OBJ.gate,FROM_OBJ.value);
		
		if(LogicImplication(graph,TotalGat,BACK.value,BACK.gate,dfrontier,SAF)==SUCCESS){
			//if(f_detect==SUCCESS) return SUCCESS;
			result=Podem_Recursion(graph,TotalGat,dfrontier,SAF);
			if(result==SUCCESS) return SUCCESS;
			else if(result == TIME_LIMIT_EXCEEDED) return TIME_LIMIT_EXCEEDED;
		}
		BACK.value=not[BACK.value];
		if(LogicImplication(graph,TotalGat,BACK.value,BACK.gate,dfrontier,SAF)==SUCCESS){
			//if(f_detect==SUCCESS) return SUCCESS;
			result=Podem_Recursion(graph,TotalGat,dfrontier,SAF);
			if(result==SUCCESS) return SUCCESS;
			else if(result == TIME_LIMIT_EXCEEDED) return TIME_LIMIT_EXCEEDED;
		}
		BACK.value=2;
		LogicImplication(graph,TotalGat,BACK.value,BACK.gate,dfrontier,SAF);
		
		return FAILURE;
	}

	void Podem(NODE *graph, int TotalGat, LIST **dfrontier, OBJECTIVE SAF,FILE *out){
		int result;		
		ResetCircuit (graph,TotalGat);
		//printf("SA_GATE=%d:::SA_VALUE=%d\n",SAF.gate, SAF.value);
		result=Podem_Recursion(graph,TotalGat, dfrontier,SAF);
		FreeList(dfrontier);
		if(result==SUCCESS)
			PrintInputs(graph,TotalGat,out);
		else if(result == TIME_LIMIT_EXCEEDED){
			//printf("OUT OF TIME\n");
			count++;
		}	
		else{
			//printf("ERROR::FAULT IS UNTESTABLE\n");
			test++;
		}	
	}

	void PrintInputs(NODE *graph, int Tgat, FILE *out){
		int i;
		for(i=1;i<=Tgat;i++){
			if(graph[i].Type==INPT){
				if(graph[i].Cval==3){
					graph[i].Cval=1;
					//printf("%d",graph[i].Cval);
					fprintf(out,"%d",graph[i].Cval);
				}
				else if(graph[i].Cval==4){
					graph[i].Cval=0;
					//printf("%d",graph[i].Cval);
					fprintf(out,"%d",graph[i].Cval);
				}
				else{
					if(graph[i].Cval==2){
						//printf("x");
						fprintf(out,"x");
					}
					else{
						//printf("%d",graph[i].Cval);
						fprintf(out,"%d",graph[i].Cval);
					}
				}
			
			}
		}
		//printf("\n");
		fprintf(out,"\n");

	}




		
		
	

        
		
