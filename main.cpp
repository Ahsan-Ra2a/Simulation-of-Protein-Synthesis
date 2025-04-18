#include <iostream>
#include <cstring>


class dna_rna_aminoacids
{
	char dna[1000], rna[50][1000];
	int k, val;
	int value[70], valend[70];

public:
	dna_rna_aminoacids()
	{
		k = 0;
		val = 0;

	loop:
		std::cin >> dna;
		int j = 0;

		int len = strlen(dna);
		--len;
		int i = 0;
		while (dna[i] != '\0')
		{
			if ((dna[i] != 'a' && dna[i] != 'A' && dna[i] != 't') && dna[i] != 'T' && dna[i] != 'c' && dna[i] != 'C' && dna[i] != 'g' && dna[i] != 'G')
			{
				std::cout << "Invalid string\nenter another string:";
				goto loop;
			}
			i++;
		}
		i = 0;
		int m = 0;

		while (dna[i] != '\0')
		{
			if ((dna[i] == 'a' || dna[i] == 'A') && (dna[i + 1] == 't' || dna[i + 1] == 'T') && (dna[i + 2] == 'g' || dna[i + 2] == 'G'))
			{
				goto loop3;
			}
			i += 3;
		}
		std::cout << std::endl
			 << "protein is not present" << std::endl;
		exit(1);
	loop3:
		i = 0;
		while (dna[i] != '\0')
		{
			if ((dna[i] == 'a' || dna[i] == 'A') && (dna[i + 1] == 't' || dna[i + 1] == 'T') && (dna[i + 2] == 'g' || dna[i + 2] == 'G'))
			{
				m = i;
				while (dna[m] != '\0')
				{
					if ((dna[m] == 't' || dna[m] == 'T') && ((dna[m + 1] == 'a' || dna[m + 1] == 'A') || (dna[m + 1] == 'g' || dna[m + 1] == 'G')) && ((dna[m + 2] == 'a' || dna[m + 2] == 'A') || (dna[m + 2] == 'g' || dna[m + 2] == 'G')))
					{

						goto loop2;
					}
					m += 3;
				}
			}
			i += 3;
		}
		std::cout << std::endl
			 << "protein is not present" << std::endl;
		exit(1);
	loop2:
		i = 0;
		while (dna[i] != '\0')
		{

			if ((dna[i] == 'a' || dna[i] == 'A') && (dna[i + 1] == 't' || dna[i + 1] == 'T') && (dna[i + 2] == 'g' || dna[i + 2] == 'G'))
			{
				j = i;
				while ((dna[i] != 't' || dna[i] != 'T') && ((dna[i + 1] != 'a' || dna[i + 1] != 'A') || (dna[i + 1] != 'g' || dna[i + 1] != 'G')) && ((dna[i + 2] != 'a' || dna[i + 2] != 'A') || (dna[i + 2] != 'g' || dna[i + 2] != 'G')))
				{
					i += 3;
					if ((dna[i] == 't' || dna[i] == 'T') && ((dna[i + 1] == 'a' || dna[i + 1] == 'A') || (dna[i + 1] == 'g' || dna[i + 1] == 'G')) && ((dna[i + 2] == 'a' || dna[i + 2] == 'A') || (dna[i + 2] == 'g' || dna[i + 2] == 'G')))
					{

						goto l1;
					}
					if (dna[i] == '\0')
					{
						goto l1;
					}
				}
			l1:
				convert(j, i + 3);
				i += 3;
				++k;

				std::cout << std::endl;
			}

			i += 3;
		}
	}

	void convert(int start, int end)
	{
		int m = 0;
		value[val] = start;
		valend[val] = end - 1;
		while (start != end)
		{
			if (dna[start] == 'T' || dna[start] == 't')
			{
				if (dna[start] == 't')
				{
					rna[k][m] = 'u';
					++m;
				}
				else
				{
					rna[k][m] = 'U';
					++m;
				}

				start++;
			}
			else
			{
				rna[k][m] = dna[start];
				++m;
				start++;
			}
		}
		rna[k][m] = '\0';

		divide();
	}

	void find(char ch[3])
	{
		if (ch[0] != '\0' && ch[1] != '\0' && ch[2] != '\0')
		{
			switch (ch[0])
			{
			case 'u':
			case 'U':
			{
				switch (ch[1])
				{
				case 'u':
				case 'U':
				{
					switch (ch[2])
					{
					case 'u':
					case 'U':
					case 'c':
					case 'C':
					{
						std::cout << "F";
						break;
					}
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "L";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				case 'c':
				case 'C':
				{
					switch (ch[2])
					{
					case 'U':
					case 'u':
					case 'C':
					case 'c':
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "S";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				case 'A':
				case 'a':
				{
					switch (ch[2])
					{
					case 'u':
					case 'U':
					{
						std::cout << "Y";
						break;
					}
					case 'c':
					case 'C':
					{
						std::cout << "Y";
						break;
					}
					case 'A':
					case 'a':
					case 'g':
					case 'G':
					{
						std::cout << ".";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				case 'G':
				case 'g':
				{
					switch (ch[2])
					{
					case 'u':
					case 'U':
					case 'C':
					case 'c':
					{
						std::cout << "C";
						break;
					}
					case 'g':
					case 'G':
					{
						std::cout << "W";
						break;
					}
					case 'a':
					case 'A':
					{
						std::cout << ".";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				}
			}
			default:
			{
				break;
			}
			break;
			case 'C':
			case 'c':
			{
				switch (ch[1])
				{
				case 'U':
				case 'u':
				{
					std::cout << "L";
					break;
				}
				case 'C':
				case 'c':
				{
					std::cout << "P";
					break;
				}
				case 'A':
				case 'a':
				{
					switch (ch[2])
					{
					case 'U':
					case 'u':
					case 'C':
					case 'c':
					{
						std::cout << "H";
						break;
					}
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "Q";
						break;
					}
					}
					break;
				}
				case 'G':
				case 'g':
				{
					std::cout << "R";
					break;
				}
				default:
					break;
				}
			}
			break;
			case 'A':
			case 'a':
			{
				switch (ch[1])
				{
				case 'U':
				case 'u':
				{
					switch (ch[2])
					{
					case 'U':
					case 'u':
					case 'C':
					case 'c':
					case 'A':
					case 'a':
					{
						std::cout << "I";
						break;
					}
					case 'G':
					case 'g':
					{
						std::cout << "M";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				case 'C':
				case 'c':
				{
					switch (ch[1])
					{
					case 'U':
					case 'u':
					case 'C':
					case 'c':
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "T";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				case 'A':
				case 'a':
				{
					switch (ch[2])
					{
					case 'U':
					case 'u':
					case 'C':
					case 'c':
					{
						std::cout << "N";
						break;
					}
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "K";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				case 'G':
				case 'g':
				{
					switch (ch[2])
					{
					case 'U':
					case 'u':
					case 'C':
					case 'c':
					{
						std::cout << "S";
						break;
					}
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "R";
						break;
					}
					default:
					{
						break;
					}
					}
					break;
				}
				default:
				{
					break;
				}
				}
			}
			break;

			case 'G':
			case 'g':
				switch (ch[1])
				{
				case 'U':
				case 'u':
				{
					std::cout << "V";
					break;
				}
				case 'c':
				case 'C':
				{
					std::cout << "A";
					break;
				}
				case 'G':
				case 'g':
				{
					std::cout << "G";
					break;
				}
				case 'A':
				case 'a':
				{
					switch (ch[2])
					{
					case 'u':
					case 'U':
					case 'c':
					case 'C':
					{
						std::cout << "D";
						break;
					}
					case 'A':
					case 'a':
					case 'G':
					case 'g':
					{
						std::cout << "E";
						break;
					}
					}
					break;
				}
				default:
					break;
				}
				break;
			}
		}
	}

	void divide()
	{
		int i = 0, j = 1, l = 0;
		char c[3];
		while (rna[k][i] != '\0')
		{

			c[0] = rna[k][i];
			++i;

			c[1] = rna[k][i];
			++i;
			c[2] = rna[k][i];
			++i;

			find(c);
		}
		std::cout << "   " << value[val] << " - " << valend[val];
		val++;
	}
};

main()
{
	dna_rna_aminoacids d;

	return 0;
}
