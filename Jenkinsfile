pipeline {
    agent any

    stages {
        stage('Install Tools') {
            steps {
                sh '''
                wget --quiet -O - https://github.com/conan-io/conan/releases/download/2.15.1/conan-2.15.1-linux-x86_64.tgz | tar -xz

                bin/conan profile detect -f
                '''
            }
        }
        
        stage('Tools Information') {
            steps {
                sh "g++ --version"
                sh "make --version"
                sh "cmake --version"
                sh "bin/conan --version"
                sh "ls -al"
            }
        }

	    stage("SAST") {
            steps {
                sh '''
		        cppcheck --enable=warning --library=posix --error-exitcode=1 -I include sources
                '''
            }
        }
	    
        stage("Build") {
            steps {
                sh '''
                #bin/conan install . --output-folder=. --build=missing
                ./tt
                #cd build
                #cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="`pwd`/Release/generators/conan_toolchain.cmake" -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release
                #source ./Release/generators/conanbuild.sh
                #cmake --build .
                #source ./Release/generators/deactivate_conanbuild.sh
                '''
            }
        }

        stage("Tests") {
            steps {
                sh '''
                source build/Release/generators/deactivate_conanbuild.sh
                ctest --test-dir build/test
                source build/Release/generators/deactivate_conanbuild.sh
                '''
            }
        }
    }
}
