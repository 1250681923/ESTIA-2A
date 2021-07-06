import java.util.ArrayList; 
import java.util.Scanner;
public class MenuRun {
	public static void main(String args[]) {
		EmployeDAOModele employeDAOModele = new EmployeDAOModele();
		Scanner scan = new Scanner(System.in); 
		boolean fin = false; 
		while (!fin) { 
			System.out.println("Faites votre choix :"); 
			System.out.println("---------------------------------------"); 
			System.out.println("(1) Montrer tous les employés"); 
			System.out.println("(2) Rechercher un employé par son ID"); 
			System.out.println("(3) Insérer un employé");
            System.out.println("(4) Vérfier login/mot de passe d'un employé"); 
            System.out.println("(5) Quitter"); 
            System.out.println("---------------------------------------"); 
            System.out.println("");
// entrée clavier entier 
            String choixString = scan.nextLine(); 
            int choix; 
            try { 
            	choix = Integer.parseInt(choixString); 
            } 
            catch(NumberFormatException e) { 
            	choix = 0; 
            	System.out.println("Sélectionner un menu de 1 à 5"); 
            	}
            switch (choix) 
           {
            case 1 : 
            System.out.println("1 - Les employées :");
            ArrayList<EmployeBeanModele> listeEmploye = employeDAOModele.lireListe(); 
            for(int i = 0 ; i < listeEmploye.size(); i++) 
            {
            	EmployeBeanModele employe = listeEmploye.get(i); 
            	System.out.println("Employé: "+employe.getId()+", "+employe.getNom()+", "+employe.getLogin());
            	System.out.println("date: "+employe.getDatetimecreation().toString());
            	System.out.println("datenaissance: "+employe.getDatenaissance());
            }
            break; 
            case 2 : 
            	System.out.println("2 - Rechercher un employé :"); 
            	System.out.print("id : "); 
            	String idstring = scan.nextLine(); 
            	int id = Integer.parseInt(idstring);
                EmployeBeanModele employe = employeDAOModele.lire(id);
                System.out.println("Employe:"+employe.getId()+","+employe.getNom()+","+employe.getLogin());
                System.out.println("date: "+employe.getDatetimecreation().toString());
            	System.out.println("datenaissance: "+employe.getDatenaissance());
            break; 
            case 3 : 
            	System.out.println("3 - Insérer un employé :"); 
            	System.out.print("Nom : "); 
            	String nom = scan.nextLine(); 
            	System.out.print("login : "); 
            	String login = scan.nextLine(); 
            	System.out.print("mdp : "); 
            	String mdp = scan.nextLine(); 
            	System.out.println("***");
            	EmployeBeanModele employe1 = new EmployeBeanModele();
            	employe1.setNom(nom);
            	employe1.setLogin(login);
            	employe1.setMdp(mdp);
            	employeDAOModele.creer(employe1);
            break; 
            case 4 : 
            	System.out.println("4 - Vérification :"); 
            	System.out.print("login : "); 
            	String login1 = scan.nextLine(); 
            	System.out.print("mdp : "); 
            	String mdp1 = scan.nextLine(); 
            	System.out.println("***");
            	int res = employeDAOModele.verifier(login1, mdp1);
            	if(res==1) {
            		System.out.println("Login et mot de passe correctes.");
            	}
            	else {
            		System.out.println("Login ou mot de passe errone");
            	}
// Demander à l'utilisateur de rentrer login et mot de passe 
// Vérifier si le login existe et si le mot de passe est le bon mot de passe 
            break; 
            case 5 :
            	fin = true; 
            break;
}
} scan.close();
}
}
