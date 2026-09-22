<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
		<head>
				<meta charset="UTF-8">
				<title>Insert title here</title>
		</head>
		<body>
						<h1>Bienvenue dans la page d'indentification <br> Veuillez Renseigner les champs du formulaire  </h1>
						<hr>
						<form 	 action="<%= request.getContextPath()  %>" 	method="post">
								<label   	for="nom">Nom: </label> 
								<input 	type="text" name="nom"  /> 
								<br>
								<label   	for="prenom">Prenom: </label> 
								<input 	type="text" name="prenom"  /> 
								<br>
								<label   	for="numero">Numero etudiant: </label> 
								<input 	type="text" name="numero"  /> 
								<br>
								<input  type="submit"    value="Envoyer"  /> 
							</form>
		</body>
</html>