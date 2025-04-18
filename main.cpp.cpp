#include<iostream>
#include<cstring>
using namespace std;

class dna_rna_aminoacids{
	char dna[1000],rna[50][1000];
	int k,val;
	int value[70],valend[70];
	public:
			dna_rna_aminoacids(){
				k=0;
				val=0;
				
		loop:	cin>>dna;
			int j=0;
			
			int len=strlen(dna);
			--len;
			int i=0;
			while(dna[i]!='\0'){
				if((dna[i]!='a'&&dna[i]!='A'&&dna[i]!='t')&&dna[i]!='T'&&dna[i]!='c'&&dna[i]!='C'&&dna[i]!='g'&&dna[i]!='G'){
					cout<<"Invalid string\nenter another string:";
					goto loop;
				}
				i++;
			}
			i=0;
			int m=0;
			
				while(dna[i]!='\0'){
				if((dna[i]=='a'|| dna[i]=='A')&&(dna[i+1]=='t'||dna[i+1]=='T')&&(dna[i+2]=='g'||dna[i+2]=='G')){
					goto loop3;
				}
				i+=3;
			}
			cout<<endl<<"protein is not present"<<endl;
				exit(1);
		loop3:
		i=0;
			while(dna[i]!='\0'){
				if((dna[i]=='a'|| dna[i]=='A')&&(dna[i+1]=='t'||dna[i+1]=='T')&&(dna[i+2]=='g'||dna[i+2]=='G')){
				m=i;
					while(dna[m]!='\0'){
	if((dna[m]=='t'||dna[m]=='T')&&((dna[m+1]=='a'||dna[m+1]=='A')||(dna[m+1]=='g'||dna[m+1]=='G'))&&((dna[m+2]=='a'||dna[m+2]=='A')||(dna[m+2]=='g'||dna[m+2]=='G'))){
					    	
					   goto loop2;
						}
							m+=3;
						}
					
					}
					i+=3;
				}
				cout<<endl<<"protein is not present"<<endl;
				exit(1);
	loop2:
			i=0;
			while(dna[i]!='\0')
			{
					
				if((dna[i]=='a'|| dna[i]=='A')&&(dna[i+1]=='t'||dna[i+1]=='T')&&(dna[i+2]=='g'||dna[i+2]=='G'))
				{
j=i;
					while((dna[i]!='t'||dna[i]!='T')&&((dna[i+1]!='a'||dna[i+1]!='A')||(dna[i+1]!='g'||dna[i+1]!='G'))&&((dna[i+2]!='a'||dna[i+2]!='A')||(dna[i+2]!='g'||dna[i+2]!='G'))){
					    i+=3;
					    if((dna[i]=='t'||dna[i]=='T')&&((dna[i+1]=='a'||dna[i+1]=='A')||(dna[i+1]=='g'||dna[i+1]=='G'))&&((dna[i+2]=='a'||dna[i+2]=='A')||(dna[i+2]=='g'||dna[i+2]=='G'))){
					    	
					    	goto l1;
						}
					    if(dna[i]=='\0'){
					    goto l1;
						}
					}
		l1:			
					convert(j,i+3); 
					i+=3;
					++k;
				
				cout<<endl;
				
				}
				
			i+=3;
		}
		
				
			
		}
	
			void convert(int start,int end){
			int m=0;
			value[val]=start;
			valend[val]=end-1;
			while(start!=end){
				if(dna[start]=='T'||dna[start]=='t'){
					if(dna[start]=='t'){
						rna[k][m]='u';
						++m;
					}
					else{
						rna[k][m]='U';
						++m;
					}
				
					start++;
				}
				else{
						rna[k][m]=dna[start];
						++m;
						start++;
				}
			}
			rna[k][m]='\0';
		
		divide();
			
		}
			
		
	


void find(char ch[3]) {
	if(ch[0]!='\0'&&ch[1]!='\0'&&ch[2]!='\0') 
	{
		switch(ch[0]) 
		{
			case 'u': case 'U': 
			{
				switch(ch[1]) 
				{
					case 'u': case 'U': {
						switch(ch[2]) {
							case 'u': case 'U': case 'c': case 'C': {
								cout<<"F";
								break;
							}
							case 'A': case 'a': case 'G': case 'g': {
							    cout<<"L";
								break;
							}
							default: {
								break;
							}
						}
						break;
					}
					case 'c': case 'C': {
						switch(ch[2]) {
							case 'U': case 'u':
							case 'C': case 'c':
							case 'A': case 'a':
							case 'G': case 'g': {
								cout<<"S";
								break;
							}
							default: {
								break;
							}
						}
						break;
					}
					case 'A': case 'a': {
						switch(ch[2]) {
							case 'u': case 'U': {
								cout<<"Y";
								break;
							}
							case 'c': case 'C': {
								cout<<"Y";
								break;
							}
							case 'A': case 'a':
							case 'g': case 'G': {
								cout<<".";
								break;
							}
							default: {
								break;
							}
						}
						break;
					}
					case 'G': case 'g': {
						switch(ch[2]) {
							case 'u': case 'U':
							case 'C': case 'c': {
								cout<<"C";
								break;
							}
							case 'g': case 'G': {
							    cout<<"W";
							    break;
							}
							case 'a': case 'A': {
								cout<<".";
								break;
							}
							default: {
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
	case 'C': case 'c':
	{
		switch(ch[1])
	    {
	 	    case 'U' : case 'u':
	 	    	{
	 	    		cout << "L";
	 	    		break;
				}
			case 'C': case 'c':
			    {
			     	cout << "P";
			     	break;
			    } 
			case 'A': case 'a':
			    {
			    	switch(ch[2])
			    	{
			    		case 'U' : case 'u': case 'C': case 'c':
			    			{
			    				cout << "H";
			    				break;
							}
						case 'A': case 'a': case 'G' : case 'g' :
							{
								cout << "Q";
								break;
							}
					}
					break;
				}
			case 'G' : case 'g' :
			{
				cout << "R";
				break;
			}	
			default:
				break;
     	}
}
break;
case 'A': case 'a':
			{
				switch(ch[1])
				{
					case 'U': case 'u':
						{
							switch(ch[2])
							{
								case 'U': case 'u': case 'C': case 'c': case 'A': case 'a':
									{
										cout<<"I";
										break;
									}
								case 'G': case 'g':
									{
										cout<<"M";
										break;
									}
								default:
									{
										break;
									}
							}
							break;
						}
					case 'C': case 'c':
						{
							switch(ch[1])
							{
								case 'U': case 'u': case 'C': case 'c': case 'A': case 'a': case 'G': case 'g':
									{
										cout<<"T";
										break;
									}
								default:
									{
										break;
									}
							}
							break;
						}
					case 'A': case 'a':
						{
							switch(ch[2])
							{
								case 'U': case 'u': case 'C': case 'c':
									{
										cout<<"N";
										break;
									}
								case 'A': case 'a': case 'G': case 'g':
									{
										cout<<"K";
										break;
									}
								default:
									{
										break;
									}
							}
							break;
						}
					case 'G': case 'g':
						{
							switch(ch[2])
							{
								case 'U': case 'u': case 'C': case 'c':
									{
										cout<<"S";
										break;
									}
								case 'A': case 'a': case 'G': case 'g':
									{
										cout<<"R";
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

case 'G': case 'g':
		switch(ch[1])
		{
			case 'U': case 'u':
			{
				cout << "V";
				break;
			}
			case 'c': case 'C':
				{
					cout <<"A";
					break;
				}
			case 'G': case 'g':
				{
					cout << "G";
					break;
				}
			case 'A': case 'a':
				{
					switch(ch[2])
					{
						case 'u' : case 'U' : case 'c' : case 'C':
							{
								cout << "D";
								break;
							}
						case 'A' : case 'a' : case 'G' : case 'g' :
							{
								cout << "E";
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

		void divide(){
			int i=0,j=1,l=0;
			char c[3];
			while(rna[k][i]!='\0'){
		
		
			c[0]=rna[k][i]; 
			++i;
			
			c[1]=rna[k][i];
			++i;
			c[2]=rna[k][i];
			++i;
		
			
			find(c);
			
		
			}
				cout<<"   "<<value[val]<<" - "<<valend[val];
			val++;
			
		}
		
		
};

main(){
	dna_rna_aminoacids d;

	return 0;
}
