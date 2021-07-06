import java.time.LocalDateTime;
import java.time.LocalDate;
public class EmployeBeanModele {
	private int id;
	private String nom;
	private String login;
	private String mdp;
	private LocalDateTime datetimecreation;
	private LocalDate datenaissance;
	public EmployeBeanModele() {	
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getLogin() {
		return login;
	}
	public void setLogin(String login) {
		this.login = login;
	}
	public String getMdp() {
		return mdp;
	}
	public void setMdp(String mdp) {
		this.mdp = mdp;
	}

	public LocalDateTime getDatetimecreation() {
		return datetimecreation;
	}

	public void setDatetimecreation(LocalDateTime datetimecreation) {
		this.datetimecreation = datetimecreation;
	}

	public LocalDate getDatenaissance() {
		return datenaissance;
	}

	public void setDatenaissance(LocalDate datenaissance) {
		this.datenaissance = datenaissance;
	}

}
