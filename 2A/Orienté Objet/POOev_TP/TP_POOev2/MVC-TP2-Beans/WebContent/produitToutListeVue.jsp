<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Tout les produits (toutes les infos)</title>
</head>
<body>

	<table>
		<tr>
			<th>ID</th>
			<th>Nom</th>
			<th>Prix</th>
		</tr>
		<c:forEach var="num" begin="0" end="3">
			<tr>
				<td><c:out value="${produitListe[num].id}" /></td>
				<td><c:out value="${produitListe[num].nom}" /></td>
				<td><c:out value="${produitListe[num].prix}" /></td>
			</tr>
		</c:forEach>


	</table>


</body>
</html>