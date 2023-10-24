pipeline {
    agent any

    stages {
        stage('Tools Information') {
            steps {
                sh "cmake --version"
                sh "g++ --version"
                sh "ls -al"
            }
        }
    }
}