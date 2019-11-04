#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE *fp;

int main() {

	//Character constant lab by Alexander Lindahl

	fp = fopen("Character_Constants.txt", "w");

	printf("%15s | %10s | %5s\n", "Description", "Character", "Value");
	fprintf(fp, "%15s | %10s | %5s\n", "Description", "Character", "Value");

	printf("_____________________________________\n");
	fprintf(fp, "______________________________________\n");

	printf("%15s | %10s | %5d\n", "Newline", "\'\\n\'", '\n');
	fprintf(fp, "%15s | %10s | %5d\n", "Newline", "\'\\n\'", '\n');

	printf("%15s | %10s | %5d\n", "Horizontal Tab", "\'\\t\'", '\t');
	fprintf(fp, "%15s | %10s | %5d\n", "Horizontal Tab", "\'\\t\'", '\t');

	printf("%15s | %10s | %5d\n", "Vertical Tab", "\'\\v\'", '\v');
	fprintf(fp, "%15s | %10s | %5d\n", "Vertical Tab", "\'\\v\'", '\v');

	printf("%15s | %10s | %5d\n", "Backspace", "\'\\b\'", '\b');
	fprintf(fp, "%15s | %10s | %5d\n", "Backspace", "\'\\b\'", '\b');

	printf("%15s | %10s | %5d\n", "Carriage Return", "\'\\r\'", '\r');
	fprintf(fp, "%15s | %10s | %5d\n", "Carriage Return", "\'\\r\'", '\r');

	printf("%15s | %10s | %5d\n", "Form Feed", "\'\\f\'", '\f');
	fprintf(fp, "%15s | %10s | %5d\n", "Form Feed", "\'\\f\'", '\f');

	printf("%15s | %10s | %5d\n", "Backslash", "\'\\\\\'", '\\');
	fprintf(fp, "%15s | %10s | %5d\n", "Backslash", "\'\\\\\'", '\\');

	printf("%15s | %10s | %5d\n", "Single Quote", "\'\\\'\'", '\'');
	fprintf(fp, "%15s | %10s | %5d\n", "Single Quote", "\'\\\'\'", '\'');

	printf("%15s | %10s | %5d\n", "Double Quote", "\'\\\"\'", '\"');
	fprintf(fp, "%15s | %10s | %5d\n", "Double Quote", "\'\\\"\'", '\"');

	printf("%15s | %10s | %5d\n", "Null", "\'\\0\'", '\0');
	fprintf(fp, "%15s | %10s | %5d\n", "Null", "\'\\0\'", '\0');

	getchar();
	fclose(fp);
	return 0;

}