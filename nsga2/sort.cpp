#include "iostream" //was not declared in this scope

#include "global.h"
#include "rand.h"

void quicksort_front_obj(chromosome pop[], int objcount, int obj_array[], int obj_array_size)
{
    q_sort_front_obj(pop, objcount, obj_array, 0, obj_array_size - 1);
}

void q_sort_front_obj(chromosome pop[], int objcount, int obj_array[], int left, int right)
{
    int index;
    int temp;
    int i, j;
    double pivot;
    if (left < right)
    {
        index = rand_int(left, right);
        temp = obj_array[right];
        obj_array[right] = obj_array[index];
        obj_array[index] = temp;
        pivot = pop[obj_array[right]].fitness[objcount];
        i = left - 1;
        for (j = left; j < right; j++)
        {
            if (pop[obj_array[j]].fitness[objcount] <= pivot)
            {
                i += 1;
                temp = obj_array[j];
                obj_array[j] = obj_array[i];
                obj_array[i] = temp;
            }
        }
        index = i + 1;
        temp = obj_array[index];
        obj_array[index] = obj_array[right];
        obj_array[right] = temp;
        q_sort_front_obj(pop, objcount, obj_array, left, index - 1);
        q_sort_front_obj(pop, objcount, obj_array, index + 1, right);
    }
}
void quicksort_dist(chromosome pop[], int *dist, int front_size)
{
    q_sort_dist(pop, dist, 0, front_size - 1);
}

void q_sort_dist(chromosome pop[], int *dist, int left, int right)
{
    int index;
    int temp;
    int i, j;
    double pivot;
    if (left < right)
    {
        index = rand_int(left, right);
        temp = dist[right];
        dist[right] = dist[index];
        dist[index] = temp;
        pivot = pop[dist[right]].crowd_dist;
        i = left - 1;
        for (j = left; j < right; j++)
        {
            if (pop[dist[j]].crowd_dist <= pivot)
            {
                i += 1;
                temp = dist[j];
                dist[j] = dist[i];
                dist[i] = temp;
            }
        }
        index = i + 1;
        temp = dist[index];
        dist[index] = dist[right];
        dist[right] = temp;
        q_sort_dist(pop, dist, left, index - 1);
        q_sort_dist(pop, dist, index + 1, right);
    }
}
