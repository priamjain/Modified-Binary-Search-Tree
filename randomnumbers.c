#include<stdio.h>
#include<stdlib.h>

	int main()
	{FILE *ptr_file;
	char names1[45][10] = {"Priam","Naman","Jack","Apurv","Abhishek","Shivam","Shreyas","hashank","Bharath","Piyush","Aakash","Ram","Vedant","Aditya","Ijju","Alekha","Omkar","Rohith","Sudhir","Satyajeet","Smriti","Shivani","Komal","Riya","Arshad","Sudesh","Visham","Vishwa","Arpit","Sanket","Atharva","Akshay","Siddhart","Sid","Vedang","Aarti","Pooja","Amit","Indrajeet","Kalindra","Utkarsh","Kesariya","Kesar","Gunny","Sunny","Dolly","Circuit"};
	char names2[30][10] = {"Todkar","Gajul","Jain","Verma","Sharma","Agarwal","Kumar","Khan","Mehta","Jagtap","Tadsarkar","Sarda","Dighe","Mane","Mahurkar","Narayan","Teli","Deshpande","Raj","Leone","Bond","Sule","Nalawade","Gandhi","Chiravallai","Selvam","Lalitha","Dongre","Rokhde","Lokhande","Khandare","Kadam","Kokate","Gushi","Mast","Rada","Kale","Gore"};

		
		int x,p,q;

		ptr_file =fopen("randno.txt", "w");

		if (!ptr_file)
			return 1;
		
		for (x=1; x<=40000; x++)
		{
			p=rand() %44 +1;
			q=rand() %29 +1;
			fprintf(ptr_file,"%llu ", rand() % 999999999999 +99999999999);
			fprintf(ptr_file,"%d  ", rand() % 100+0);
			fprintf(ptr_file,"%s", names1[p]);
			fprintf(ptr_file,"%s\n", names2[q]);

			
		}
		fclose(ptr_file);

		return  0;
	}

