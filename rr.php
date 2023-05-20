<?php
//rmdir("uploads");

if(isset($_POST['pass']))
{
    $password = $_POST['pass'];
    if($password == "pasis12712345678")
    {
        $link = mysqli_connect("localhost","*****","*****","*****");
		mysqli_set_charset($link, "utf8");
		    if(mysqli_connect_errno())
				{
			    	exit("Error!!!!" . mysqli_connect_error());
				}
				$querys = "SELECT `codes` FROM `relay` WHERE 1";
				            $result = mysqli_query($link,$querys);
				            $row = mysqli_fetch_array($result);
							$lastpath = $row['codes'];
							echo($lastpath);
    }
    else
    {
        echo("The password is wrong!");
    }
}

if(isset($_POST['passphone']) && isset($_POST['codes']))
{
	$passphone = $_POST['passphone'];
	$codes = $_POST['codes'];
	if($passphone == "pasis12712345678")
	{
		$link2 = mysqli_connect("localhost","*****","*****","*****");
	mysqli_set_charset($link2, "utf8");
		if(mysqli_connect_errno())
			{
				exit("Error!!" . mysqli_connect_error());
			}
			$query2  = "UPDATE relay SET codes=$codes WHERE 1";
			$result2 = mysqli_query($link2,$query2);
			$row2 = mysqli_fetch_array($result2);
	}
	
	
}
?>
