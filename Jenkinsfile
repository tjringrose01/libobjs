pipeline {
    agent any

    stages {
        stage('Install Tools') {
            steps {
                sh '''
                wget https://github.com/conan-io/conan/releases/download/2.15.1/conan-2.15.1-linux-x86_64.tgz
                tar -xvf conan-2.15.1-linux-x86_64.tgz

                export PATH=$PATH:./bin

                conan profile detect -f
                '''
            }
        }
        
        stage('Tools Information') {
            steps {
                sh "g++ --version"
                sh "make --version"
                sh "cmake --version"
                sh "conan --version"
                sh "ls -al"
            }
        }

        stage("Build") {
            steps {
                sh '''
                conan install . --output-folder=. --build=missing

                cd build
                cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=`pwd`/Release/generators/conan_toolchain.cmake -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release
                source ./Release/generators/conanbuild.sh
                cmake --build .
                source ./Release/generators/deactivate_conanbuild.sh
                '''
            }
        }

        stage("SAST") {
            steps {
                sh '''
                    
                '''
            }
        }

        stage("Tests") {
            steps {
                sh '''
                source ./Release/generators/deactivate_conanbuild.sh
                ctest --test-dir test
                source ./Release/generators/deactivate_conanbuild.sh
                '''
            }
        }
    }
}
