<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link rel="stylesheet" href="/produitFormulaireCss.css">
<title>Ajouter un nouveau produit</title>
</head>
<body>
	<form action="ProduitAjoutControleur" method="post">
		id: <input type="text" name="id" /> <br />
		nom : <input type="text" name="nom" /> <br /> 
		prix : <input type="text" name="prix" /> <br />
		<input type="submit" />
	</form>

</body>
</html>