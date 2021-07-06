import java.sql.Connection; 
import java.time.LocalDate;
import java.sql.DriverManager; 
import java.sql.PreparedStatement; 
import java.sql.ResultSet; 
import java.sql.SQLException; 
import java.sql.Statement;
public class ConnexionBDDModele {
Connection connexion;
public ConnexionBDDModele() 
{
	try {
		System.out.println("Chargement de pilote JDBC<-->MySQL ..."); 
		Class.forName("com.mysql.jdbc.Driver"); 
		System.out.println("pilote chargé.");
		
		
		String utilisateurBDD = "root"; // Utilisateur de la BD 
		String motdepasseBDD = ""; // Password de l'utilisateur de la BD 
		String nomBDD = "estiajdbc"; // Nom de la BD sur laquelle nous allons acceder 
		String urlBDD = "jdbc:mysql://localhost/"+nomBDD; 
		//String urlBDD = "jdbc:mysql://localhost:8889/"+nomBDD; // Pour MacOS
		try 
		{
		connexion = DriverManager.getConnection(urlBDD, utilisateurBDD, motdepasseBDD); 
		System.out.println("Connexion établie.");
		}
		
		catch (SQLException ex) 
		{ 
			ex.printStackTrace(); 
		}
	}
		catch(ClassNotFoundException e) 
	   { 
			System.out.println(e); 
	   }
	}
public Connection getConnexion()
{
	return connexion; 
}
		public void fermerConnexion() 
		{
			try {
				connexion.close();
			}
			catch (SQLException e) 
			{ 
				e.printStackTrace(); 
			}
	    }
}
