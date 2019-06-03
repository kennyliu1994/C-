#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#define INF 1.0e14
#define EPS 1.0e-14 //nsga2

#include <stdlib.h>
#include <stdio.h> /* printf, scanf, NULL */
#include <vector>
#include <string>
using namespace std;

class chromosome
{
public:
    vector<vector<double> > alpha;
    vector<vector<double> > beta;
    vector<vector<int> > gene;
    vector<double> value;
    vector<double> Sp;
    vector<double> fitness;
    double crowd_dist;
    int np;
    int index;
    int rank;
};

typedef struct lists
{
    int index;
    struct lists *parent;
    struct lists *child;
} list;

extern int popsize;
extern int dimension;
extern int nbit;
extern int nobj;
extern int ngen;
extern int nrealcross;
extern int nrealmut;

extern vector<double> lowerbound;
extern vector<double> upperbound;
extern double pcross_real;
extern double pmut_real;
extern double eta_c;
extern double eta_m;

extern string s;

void allocate_memory(chromosome pop[], int size);

void initialize_pop(chromosome pop[]);

void decode_pop(chromosome pop[]);

void report_pop(chromosome pop[], fstream &fs);
void report_feasible(chromosome pop[], fstream &fs);

void evaluate_pop(chromosome pop[], string);

void make(chromosome pop[], chromosome new_pop[]);
void update(chromosome pop[]);
double lookup(int x, int b, int domi);

void assign_rank_and_crowding_distance(chromosome new_pop[]);

void assign_crowding_distance_list(chromosome pop[], list *lst, int front_size);
void assign_crowding_distance(chromosome pop[], int *dist, int **obj_array, int front_size);
void assign_crowding_distance_indices(chromosome pop[], int c1, int c2);

void quicksort_front_obj(chromosome pop[], int objcount, int obj_array[], int obj_array_size);
void q_sort_front_obj(chromosome pop[], int objcount, int obj_array[], int left, int right);
void quicksort_dist(chromosome pop[], int *dist, int front_size);
void q_sort_dist(chromosome pop[], int *dist, int left, int right);

void insert(list *node, int x);
list *del(list *node);

int check_dominance(chromosome a, chromosome b);

void merge(chromosome pop1[], chromosome pop2[], chromosome pop3[]);
void copy_ind(chromosome ind1, chromosome &ind2);

void fill_nondominated_sort(chromosome mixed_pop[], chromosome new_pop[]);
void crowding_fill(chromosome mixed_pop[], chromosome new_pop[], int count, int front_size, list *elite);

void selection(chromosome old_pop[], chromosome new_pop[]);
chromosome tournament(chromosome ind1, chromosome ind2);
void mutation_pop(chromosome pop[]);
void crossover(chromosome parent1, chromosome parent2, chromosome &child1, chromosome &child2);

void display(chromosome pop[], FILE *gp, int generation);

void sch1(vector<double> &value, vector<double> &fitness);
void sch2(vector<double> &value, vector<double> &fitness);
void fon(vector<double> &value, vector<double> &fitness);
void kur(vector<double> &value, vector<double> &fitness);
void pol(vector<double> &value, vector<double> &fitness);
void vnt(vector<double> &value, vector<double> &fitness);
void zdt1(vector<double> &value, vector<double> &fitness);
void zdt2(vector<double> &value, vector<double> &fitness);
void zdt3(vector<double> &value, vector<double> &fitness);
void zdt4(vector<double> &value, vector<double> &fitness);
void zdt6(vector<double> &value, vector<double> &fitness);

#endif
