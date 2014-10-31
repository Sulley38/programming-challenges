#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODES 100
#define MAXWORDS 100
#define WORDLENGTH 32

/* DAG structure */
char words[MAXNODES][MAXWORDS][WORDLENGTH];
int wordCount[MAXNODES];
int nextNode[MAXNODES][MAXWORDS];
int puns[MAXNODES];

/* Count the number of puns that can be built from the node currentNode */
void countPuns(const int currentNode) {
	puns[currentNode] = 0;
	int i, targetNode;
	for (i = 0; i < wordCount[currentNode]; ++i) {
		targetNode = nextNode[currentNode][i];
		if (targetNode == -1) {
			puns[currentNode] += 1;
		} else {
			if (puns[targetNode] == 0)
				countPuns(targetNode);
			puns[currentNode] += puns[targetNode];
		}
	}
}

/* Build and print the result */
void printPun(int target) {
	int current = 0, next, sum, i;
	while (current != -1) {
		i = sum = next = 0;
		while (sum + next < target) {
			sum += next;
			if (nextNode[current][i] == -1)
				next = 1;
			else
				next = puns[nextNode[current][i]];
			i++;
		}
		if (current != 0)
			printf("-");
		printf("%s", words[current][i-1]);
		target -= sum;
		current = nextNode[current][i-1];
	}
	putchar('\n');
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char token[WORDLENGTH];
	int currentNode, punsCounted = 0, i;
	/* Read the input */
	scanf("%*d ");
	while (!feof(stdin) && scanf("%s ", token)) {
		/* Parse the type of token read: search the colon */
		for (i = 0; token[i] != 0 && token[i] != ':'; ++i) ;
		if (token[i] == 0) {
			/* Query token */
			if (!punsCounted) {
				memset(puns, 0, sizeof puns);
				countPuns(0);
				punsCounted = 1;
			}
			printPun(atoi(token));
		} else if (token[i + 1] > 0) {
			/* Word:Node token */
			token[i] = 0;
			strncpy(words[currentNode][wordCount[currentNode]], token, WORDLENGTH);
			if (token[i + 1] == '$')
				nextNode[currentNode][wordCount[currentNode]] = -1;
			else
				nextNode[currentNode][wordCount[currentNode]] = atoi(token + i + 1);
			wordCount[currentNode]++;
		} else {
			/* Node: token */
			token[i] = 0;
			currentNode = atoi(token);
			if (currentNode == 0 && punsCounted) {
				/* Output between test cases */
				punsCounted = 0;
				putchar('\n');
			}
			wordCount[currentNode] = 0;
		}
	}

	return 0;
}
