#include <cstdio>
using namespace std;

int main(void)
{
	char str[102];
	while (fgets(str,101,stdin)) {
		printf("%s", str);
	}
}