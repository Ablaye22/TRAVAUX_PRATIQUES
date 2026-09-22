package ServletDemo;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/mvn")

public class mvn extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private String nom ;
	private String prenom;
       
   
    public mvn() {
        super();
        this.nom = "SOW";
        this.prenom = "Ablaye";
       
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out = response.getWriter();
		out.println("Bonjour");
		RequestDispatcher dispatcher = request.getRequestDispatcher("/date.jsp");
		dispatcher.forward(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
