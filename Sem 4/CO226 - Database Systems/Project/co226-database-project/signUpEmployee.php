<!DOCTYPE html>
<html>
<head>
<title>Login Form</title>
<link rel="stylesheet" type="text/css" href="stylelogin.css">
</head>


<body>
<div class="login-box">
    <img src="images2/avatar.png" class="avatar">
	<h1>Login Here</h1>
	<form  action="signUpEmployee.php" method="POST">
	<p>Username</p>
	<input type="text" name="user" placeholder="Enter Username" >
	<p>Password</p>
	<input type="password" name="pass" placeholder="Enter Password">
           <input type="submit" name="submit" value="Login" >
            <a href="signInEmployee.php"> Sign up</a>
            </form>
</div>
</body>
</html>

<?php

	$link = mysqli_connect("localhost", "root", "", "database_project");

	// Check connection
	if($link === false){
	    die("ERROR: Could not connect. " . mysqli_connect_error());
	}

  $user = 0;
  $pass = 0;
	if(isset($_POST['user']) && isset($_POST['pass'])){
		$user = $_POST['user'];
		$pass = $_POST['pass'];

		//echo "$user";

		$sql = "SELECT Password FROM users WHERE Ssn = '$user'";


$result = $link-> query($sql);
if($result->num_rows > 0){
	while($row = $result->fetch_assoc()){


	if ($row["Password"] == $pass){
		header('Location: empSearchUpdate.html');
	}
	}
}

if(mysqli_query($link, $sql)){

} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
}
	mysqli_close($link);
?>
