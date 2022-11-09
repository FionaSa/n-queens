#include "queens.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* check_same_diagonal: returns true iff queens (c0,r0) and (c1,r1) are in the
 * same diagonal. */
static bool check_same_diagonal(const int c0, const int r0,
                                const int c1, const int r1) {
    if(c0-r0 == c1-r1 || c0+r0 == c1+r1) return true;
    return false;
}

/* check_column_ok: returns true iff the placement (c,r) is ok with all queens
 * to the left of column c already placed in queen_row.
 * precondition: queen_row must be at least of size c. */
static bool check_column_ok(const int c, const int r, const int queen_row[]) {

    for(int i = 0 ; i < c ; i++)
    {
       if(check_same_diagonal(c,r,i,queen_row[i]))
            return false;
    }

    return true;
}

/* find_available: returns an available row higher than min.
 * If no row is found returns -1 */
static int find_available(const int min, const int n, const bool available[]) {

    for(int i = min+1; i < n ; i ++)
    {
        if(available[i])
            return i;
    }

    return -1;
}

/* _find_solution: tries to find a solution to the n-queens problems by filling
 * columns from c to n.
 * queen_row contains the row positions for columns lower than c.
 * available contains the available rows to fill columns higher or equal to c.
 */
static bool _find_solution(const int n, const int c, int queen_row[],
                           bool available[]) {
    //Condition de retour de la fonction récursive (càd qu'on arrive à la derniére colonne)
    //Si on arrive jusque-là et qu'il y a plus de ligne disponible, c'est qu'on a trouvé une solution
    if(n == c && (find_available(0,n,available) == -1))     

         return true;
    

    //Sinon c'est qu'on n'a pas trouvé de solution
    if(n == c) 
      return false;

    int tmp = find_available(-1,n,available);

    //On parcours toutes les lignes possibles
    while (tmp != -1)
    {
        //On cherche la premiére disponible

          
          if(tmp == -1)
          {
              return false;
          }


        //Si aucune n'a été trouvée c'est qu'il n'y a pas de solution
        if (tmp == -1)
        {
            return false;
        }
        
        //On vérifie que la ligne trouvée est ok avec les précedentes mises 
        if(check_column_ok(c,tmp,queen_row)) {
             
            queen_row[c] = tmp;
            available[tmp] = false;                    
            //On continue récursivement  
         
            if (_find_solution(n, c+1, queen_row, available))
            {
              //Si une solution a été trouvée on renvoie vrai

                return true;
            }
            else 
            //Sinon on remets la ligne en non utilisée et on continue a chercher
                {
                  queen_row[c] = -1;
                  available[tmp] = true;
                }


        }
                tmp = find_available(tmp,n,available);

    }
    //Si on arrive jusque là c'est qu'une solution n'a pas été trouvée
      return false;
 
}

/* find_solution: returns true iff a n-queens solution is found.
 * queens_row is an int array of size n that will be
 * overwritten with the solution.
 *
 * if a solution is found, queens_row[c] will contain the row number for queen
 * at column c.
 * */
bool find_solution(const int n, int queen_row[]) {
  bool available[n];
  for (int i = 0; i < n; i++) {
    available[i] = true;
  }
  return _find_solution(n, 0, queen_row, available);
}
