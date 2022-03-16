/* Opponent Program for Path Maintenance */
/* Hal Burch */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

/*
  maintain.in: input case
  maintain.key: answers
  standard input/output: competitor's running programm
  standard error: grading output
 */

#define NAME "maintain"

#define MAXNODES 1000
#define MAXYEARS 12000

unsigned int seed;

int myRand(void)
{
    seed = seed * 1103515245 + 12345;
    return seed >> 16;
}

int nNode, nYear;
int testcase;
int ans;
FILE *fkey, *fin;
int format = 0, output = 0, dump = 0;
int nTotalPaths;

int minPathCost = 1;
int maxPathCost = 10000;

int curPaths[MAXNODES+1][MAXNODES+1];
int uniquePaths;

int Pairs[MAXNODES*(MAXNODES-1)/2][2];
int nPairs;

int RandRange(int min, int max)
{
    return (myRand() % (max-min+1)) + min;
}

int GetPathLength(int from, int to)
{
    int temp;
    if (from > to) {
        temp = to;
        to = from;
        from = temp;
    }
    return curPaths[from][to];
}

void UpdatePath(int from, int to, int newCost)
{
    int temp;
    if (from > to) {
        temp = to;
        to = from;
        from = temp;
    }
    if (curPaths[from][to] == -1) {
        uniquePaths++;
    }
    if ((curPaths[from][to] == -1) || (curPaths[from][to] > newCost)) {
        curPaths[from][to] = newCost;
    }
}


void
PrintHeader(void) {
	if (fscanf (fin, "%d", &nNode) != 1) {
		fprintf (stderr, "Input file format wrong on line 1\n");
		exit(1);
	}
	if (nNode == -1) {
		int lv, lv2;

		format = 1;
		if (fscanf (fin, "%d", &testcase) != 1) {
			fprintf (stderr, "Input file format wrong on line 3\n");
			exit(1);
		}
		if (fscanf (fin, "%d %d", &nNode, &nYear) != 2) {
			fprintf (stderr, "Input file format wrong on line 2\n");
			exit(1);
		}
		if (fscanf (fin, "%d", &seed) != 1) {
			fprintf (stderr, "Input file format wrong on line 3\n");
			exit(1);
		}

		fprintf (stdout, "%d %d\n", nNode, nYear);

		nTotalPaths = 0;
		for (lv = 1; lv <= nNode; lv++)
			for (lv2 = 1; lv2 <= nNode; lv2++)
				curPaths[lv][lv2] = -1;
	} else {
		fscanf (fin, "%d", &nYear);
		printf ("%d %d\n", nNode, nYear);
	}
}

void
PrintYear(int yr) {
	int nPaths;
	int from, to, cost;
	int lv;
	int retry;
	if (format == 1) {
		if (!output && !dump) {
			if (fscanf (fkey, "%d", &ans) != 1) {
				fprintf (stderr, "Unexpected EOF of key\n");
				exit(1);
			}
		}
		nPaths = 1;
            	nTotalPaths += nPaths;
            	for (lv = 0; lv < nPaths; lv++) {
                	// Select endpoints
			if (nPairs) {
				int idx = RandRange(0, nPairs-1);
				from = Pairs[idx][0];
				to = Pairs[idx][1];
				Pairs[idx][0] = Pairs[nPairs-1][0];
				Pairs[idx][1] = Pairs[nPairs-1][1];
				nPairs--;
			} else {
	                    	from = RandRange(1, nNode);
	                    	do {
	                        	to = RandRange(1, nNode);
	                    	} while (from == to);
			}
	
                	// Select cost
                	cost = RandRange(minPathCost, maxPathCost);
	
                	fprintf(stdout, "%d %d %d\n", from, to, cost);
                	UpdatePath(from, to, cost);
		}
	} else {
		if (fscanf (fkey, "%d", &ans) != 1) {
			fprintf (stderr, "Unexpected EOF of key\n");
			exit(1);
		}
		nPaths = 1;
		for (lv = 0; lv < nPaths; lv++) {
			if (fscanf (fin, "%d %d %d", &from, &to, &cost) != 3) {
				fprintf (stderr, "Problem reading year %d\n", yr+1);
				exit(1);
			}
			fprintf (stdout, "%d %d %d\n", from, to, cost);
		}
	}
}

int
ReadAnswer(int yr) {
	int ans;
	fd_set rfd;
	struct timeval tval;
	char line[1000];
	char *cp;

	if (!fgets(line, sizeof(line), stdin)) {
		FD_ZERO(&rfd);
		FD_SET(0, &rfd);
	
		tval.tv_sec = 5;
		tval.tv_usec = 0;

		select(1, &rfd, NULL, NULL, &tval);
		if (!fgets(line, sizeof(line), stdin)) {
			fprintf (stderr, "Wrong: no output for year %d\n", yr+1);
			exit(1);
		}
	}

	line[sizeof(line)-1] = '\0';
	if (line[0] == '-' && line[1] == '1' && (line[2] == '\n' || line[2] == '\0')) return -1;
	ans = -1;
	for (cp = line; *cp && *cp != '\n'; cp++) {
		if (*cp < '0' || *cp > '9') break;
		if (ans == -1) ans = 0;
		ans = 10*ans + *cp - '0';
	}
	if (*cp == '\n') *cp = '\0';
	if (ans == -1 || *cp) {
		fprintf (stderr, "Invalid answer for year %d: \"%s\"\n", yr+1, line);
		exit(1);
	}

	return ans;
}

int
main(int argc, char **argv) {
	int lv, lv2;
	int repl;

	if (argc > 1 && strcasecmp(argv[1], "-output") == 0) {
		output++;
		argc--;
		argv++;
	}
	if (argc > 1 && strcasecmp(argv[1], "-dump") == 0) {
		dump++;
		argc--;
		argv++;
	}

	if (!output && !dump) {
		fkey = fopen(NAME ".key", "r");
	} else fkey = stdin;
	if (argc > 1) fin = fopen(argv[1], "r");
	else fin = fopen(NAME ".in", "r");

	assert(fin && fkey);

	fcntl(0, F_SETFL, O_NONBLOCK);

	PrintHeader();
#if 0
	fprintf (stderr, "output = %d, format = %d\n", output, format);
#endif
	nPairs = 0;
	for (lv = 1; lv <= nNode; lv++)
		for (lv2 = lv+1; lv2 <= nNode; lv2++) {
			Pairs[nPairs][0] = lv;
			Pairs[nPairs][1] = lv2;
			nPairs++;
		}

	for (lv = 0; lv < nYear; lv++) {
		PrintYear(lv);
		fflush(stdout);
		if (!dump) {
			repl = ReadAnswer(lv);
			if (!output && (ans != repl)) {
				fprintf (stderr, "WRONG\n");
				if(repl == -1)
fprintf (stderr,
	"In week %d, your program found could not find a set of trails,\n"
	"but a set with total length %d exists.\n", lv+1, ans);
				else if(ans == -1)
fprintf (stderr,
	"In week %d, your program claimed to find a set of trails with\n"
	"total length %d, but no such set exists.\n",
	lv+1, repl);
				else
fprintf (stderr, 
	"In week %d, your program found a total trail length of %d,\n"
	"but a total trail length of %d is possible.\n",
	lv+1, repl, ans);
				fprintf (stdout, "ABORT\n");
				exit(0);
			} else if (output)
				fprintf (stderr, "%d\n", repl);
		}
	}

	if (!output && !dump) {
		fprintf (stderr, "OK\n");
		fprintf (stdout, "DONE\n");
	}
	return 0;
}
