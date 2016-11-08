package Code39;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Code39 {
	int MAX_CHAR=100;
	
	public static String code39(String chaine)
	{
		int i;
		String chaine_code=new String("*");
		String char_ok=new String("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789+-/.$%");

		for(i=0;i<chaine.length();i++)
		{
			if (char_ok.indexOf(chaine.charAt(i))!=-1)
			{
				chaine_code+=Character.toUpperCase(chaine.charAt(i));
			}
			else
			{
				System.exit(0);
			}
		}
		chaine_code+="*";
		return chaine_code;
	}
	
	public static int test_chaine(String chaine)
	{
		int i,j,test=0;

		String char_ok=new String("ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789$-/.%+");
		if (chaine.charAt(0)=='*' && chaine.charAt(chaine.length()-1)=='*')
		{
			for (i=1;i<chaine.length()-1;i++)
			{
				for (j=0;j<43;j++)
				{
					if (chaine.charAt(i)==char_ok.charAt(j))
					test++;
				}
			}
			if(test+2==chaine.length())
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
	
	public static String modulo43(String chaine)
	{
		int sum=0,i,j;
		String char_ok=new String("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%");

		for (i=0;i<chaine.length();i++)
		{
			for(j=0;j<43;j++)
			{
				if(chaine.charAt(i)==char_ok.charAt(j)) sum+=j;
			}
		}
		chaine+=char_ok.charAt(sum%43);

		return chaine;
	}
	
	public static void main(String[] arg) throws IOException
	{
		/*String test=code39("abc 123//$$");
		System.out.println(test);
		System.out.println(test_chaine(test));
		System.out.println(modulo43(test));*/
		
		BufferedReader buffer_chaine=new BufferedReader(new InputStreamReader(System.in));
		String chaine=new String();
		
		chaine=buffer_chaine.readLine();
		System.out.println(code39(chaine));
		chaine=code39(chaine);
		System.out.println(test_chaine(chaine));
		System.out.println(modulo43(chaine));
	}
}

