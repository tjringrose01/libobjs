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
                '''
                cmake .
                make
                '''
            }
        }
    }
}