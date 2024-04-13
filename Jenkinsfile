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
                cmake --build .
                '''
            }
        }

        stage("SAST") {
            steps {
                sh '''
                    cppcheck --enable=all --inconclusive --library=posix include/ sources/ test/ bin/
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
