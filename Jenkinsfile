pipeline {
    agent any

    stages {
        stage('Tools Information') {
            steps {
                sh "g++ --version"
                sh "make --version"
                sh "cmake --version"
                sh "ls -al"
            }
        }

        stage("Build") {
            steps {
                sh '''
                cmake .
                make
                '''
            }
        }

        stage("Tests") {
            steps {
                echo "Tests"
                sh "bin/unit_tests"
            }
        }
    }
}