import java.util.*;
public class Main{
	private static final boolean DEBUG=true;
	/*
	class graph{
		private ArrayList<ArrayList<String>> edges;
		graph(String s[]){
			edges=new ArrayList<ArrayList<String>>();
			for(int i=0;i<s.length;i++){
				String Vs=s[i].split(" ");
				if(Vs.length==2){
					edges.add(Vs[0]);
					
				}
			}
		}
	}
	*/
	HashSet<String> isFathers=new HashSet<String>();
	HashSet<String> isSons=new HashSet<String>();
	boolean isFather(String father,String son){
		String s=father+son;
		if(isFathers.contains(s)) return true;
		return false;
	}
	boolean isSon(String father,String son){
		String s=father+son;
		if(isSons.contains(s)) return true;
		return false;
	}
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String s=in.nextLine();
		String includes[]=s.split(";");
		if(DEBUG){
			for(int i=0;i<includes.length;i++){
				System.out.println(includes[i]);
			}
		}
		StringBuffer ans1=new StringBuffer();
		for(int i=0;i<includes.length;i++){
			String vars=includes[i].split(" ");
			if(vars.length==2){
				isFathers.add(vars[0]+vars[1]);
				isSons.add(vars[0])
			}
		}
	}
}