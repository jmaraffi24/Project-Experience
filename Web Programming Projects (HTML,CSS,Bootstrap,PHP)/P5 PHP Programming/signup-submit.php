<!DOCTYPE html>
<html>

    <!-- shared page top HTML -->

    <head>
        <title>Match</title>

        <meta charset="utf-8" />

        <!-- instructor-provided CSS and JavaScript links; do not modify -->
        <link href="heart.gif" type="image/gif" rel="shortcut icon" />
        <link href="match.css" type="text/css" rel="stylesheet" />

        <script src="http://ajax.googleapis.com/ajax/libs/prototype/1.7.0.0/prototype.js" type="text/javascript"></script>
    </head>

    <body>
        <div id="bannerarea">
            <img src="match.png" alt="banner logo" /> <br />
        </div>

        <!-- your HTML output follows -->

        <?php

        $isValid = true;
        $myfile = fopen("singles.txt", "a") or die("Unable to open file!");
        $name = $_GET["name"];
        if($name==''){
          //  $isValid = false;
        }


        $gender = $_GET["gender"];
        if($gender != 'M'||$gender != 'F'){
          //  $isValid=false;
        }


        $age = $_GET["age"];
        if(!preg_match('/^\d{0,99}$/',$age)){
          //  $isValid = false;
        }

        $personality = $_GET["personality"];
        if(!preg_match('/[IE][NS][TF][JP]/',$personality)){
           // $isValid =false;
        }


        $os = $_GET["os"];


        $minage = $_GET["minage"];


        $maxage = $_GET["maxage"];

        if(!preg_match('/^\d{0,99}$/',$minage)||!preg_match('/^\d{0,99}$/',$maxage)||$minage>$maxage){
            $isValid = false;
        }



        if($isValid==false){
            header("Location: ./signup.php");
        }
        else{
            fwrite($myfile, $name);
            fwrite($myfile, ',');
            fwrite($myfile, $gender);
            fwrite($myfile, ',');
            fwrite($myfile, $age);
            fwrite($myfile, ',');
            fwrite($myfile, $personality);
            fwrite($myfile, ',');
            fwrite($myfile, $os);
            fwrite($myfile, ',');
            fwrite($myfile, $minage);
            fwrite($myfile, ',');
            fwrite($myfile, $maxage);
            fwrite($myfile, PHP_EOL);
        }

        fclose($myfile);
        ?>

        <strong>Thank You!</strong>
        <p>Welcome to Match, <?php print $name ?>!</p>
        <p>Now <a href="matches.php">Log in to see your matches!</a></p>
        <!-- shared page bottom HTML -->
        <div>
            <p>
                This page is for single nerds to meet and date each other!  Type in your personal information and wait for the geek love to begin!  Thank you for using our site.
            </p>

            <p>
                Results and page (C) Copyright Match Inc.
            </p>

            <ul>
                <li>
                    <a href="index.php">
                        <img src="back.gif" alt="icon" />
                        Back to front page
                    </a>
                </li>
            </ul>
        </div>

    </body>
</html>
