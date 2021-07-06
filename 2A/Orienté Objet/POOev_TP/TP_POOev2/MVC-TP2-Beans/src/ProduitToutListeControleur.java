

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ProduitToutListeControleur
 */
@WebServlet("/ProduitToutListeControleur")
public class ProduitToutListeControleur extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ProduitToutListeControleur() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ProduitBeanModele produit1 = new ProduitBeanModele();
		ProduitBeanModele produit2 = new ProduitBeanModele();
		ProduitBeanModele produit3 = new ProduitBeanModele();
		ProduitBeanModele produit4 = new ProduitBeanModele();
		produit1.setId(1);
		produit2.setId(2);
		produit3.setId(3);
		produit4.setId(4);
		
		ArrayList<ProduitBeanModele> produitListe = new ArrayList<ProduitBeanModele>();
		produitListe.add(produit1);
		produitListe.add(produit2);
		produitListe.add(produit3);
		produitListe.add(produit4);
		
		request.setAttribute("produitListe", produitListe);
		request.getRequestDispatcher("/produitToutListeVue.jsp").forward(request, response);
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
