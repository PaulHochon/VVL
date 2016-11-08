package Code39;
import junit.framework.*;
import Code39.Code39;
public class TestCode39 extends TestCase{
	
	public void test_uni_test_chaine() throws Exception
	{
		assertEquals("*ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789./-+$%*",Code39.code39("abcdefghijklmnopqrstuvwxyz 0123456789./-+$%"));
		assertFalse("ABC */AZE98.."==Code39.code39("ABC */AZE98.."));
		assertFalse("aB0 r3712//"=="*aB0 r3712//*");
		assertEquals("**",Code39.code39(""));
	}
	
	public void test_uni_modulo43() throws Exception
	{
		assertEquals("*012*3",Code39.modulo43("*012*"));
		assertEquals("*ABC*X",Code39.modulo43("*ABC*"));
		assertEquals("**0",Code39.modulo43("**"));
	}
}	
