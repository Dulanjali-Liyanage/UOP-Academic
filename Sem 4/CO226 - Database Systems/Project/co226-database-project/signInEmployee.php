<!DOCTYPE html>
<html>
<head>
<title>Login Form</title>
<link rel="stylesheet" type="text/css" href="stylelogin.css">
</head>


<body>
<div class="login-box">
    <img src="images2/avatar.png" class="avatar">
	<h1>Sign Up Here</h1>
	<form  action="signInEmployee.php" method="POST">
	<p>Username</p>
	<input type="text" name="user" placeholder="Enter Username" >
	<p>Password</p>
	<input type="password" name="pass" placeholder="Enter Password">
           <input type="submit" name="submit" value="Sign Up" >

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

	if(isset($_POST['user']) && isset($_POST['pass'])){
		$user = $_POST['user'];
		$pass = $_POST['pass'];


		$sql = "SELECT firstName FROM employee WHERE ssn = '$user'";
	 $result = $link-> query($sql);
if($result->num_rows > 0){
         $sql ="SELECT Password FROM users WHERE Ssn = '$user'";


      //  $sql = "INSERT INTO users (Ssn,Password) VALUES($user,'$pass')";

        $result = $link-> query($sql);
		if($result->num_rows > 0){

		$sql = "UPDATE users SET Password = '$pass' WHERE Ssn = '$user'";
		}else{

		 $sql = "INSERT INTO users (Ssn,Password) VALUES($user,'$pass')";
		}
header('Location:signUpEmployee.php');

}







if(mysqli_query($link, $sql)){

} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
}
	mysqli_close($link);
?>
