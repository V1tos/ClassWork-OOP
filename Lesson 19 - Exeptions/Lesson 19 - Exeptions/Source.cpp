#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

using namespace std;


//int main() {




	enum { test_error = 1 };

	int main(void) {
		errinfo err;
		ERRTRY(err,
			ERRTHROW(err, test_error); /* Comment this out for no error */
		puts("No error");
		)ERRCATCH(err,
			printf("Caught error (type = %i)\n", ERRGET(err));
		);

			ERRTHROW(err, test_error); /* Throwing outside of try block does nothing */

			system("pause");
		return (EXIT_SUCCESS);
		
	}


//	system("pause");
//	return 0;
//}