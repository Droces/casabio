<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPDICOM;

use PHPExiftool\Driver\AbstractTag;

class PatientBirthDate extends AbstractTag
{

    protected $Id = 'PatientDOB';

    protected $Name = 'PatientBirthDate';

    protected $FullName = 'XMP::DICOM';

    protected $GroupName = 'XMP-DICOM';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-DICOM';

    protected $g2 = 'Image';

    protected $Type = 'date';

    protected $Writable = true;

    protected $Description = 'Patient Birth Date';

    protected $local_g2 = 'Time';

}
